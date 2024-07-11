import joblib
from fastapi import FastAPI
from pydantic import BaseModel
import numpy as np

app = FastAPI()

class Item(BaseModel):
    duration : int
    campaign : int
    pdays : int
    previous : int
    job : str
    marital : str
    education : str
    default : str
    housing : str
    loan : str
    contract : str
    
def load_package(model_package):
    model = model_package['model']
    encoder = model_package['encoder']
    scaler = model_package['scaler']
    return model, encoder, scaler
    
@app.post("/predict")
def predict(item: Item):
    model = joblib.load("model_package.pkl")
    data = item.model_dump()
    
    numerical_data = [[data['duration'], data['campaign'], data['pdays'], data['previous']]]
    categorical_data = [[data['job'], data['marital'], data['education'], data['default'], data['housing'], data['loan'], data['contract']]]
    
    model, encoder, scaler = load_package(model)
    
    # Encode the categorical data
    categorical_data_encoded = encoder.transform(categorical_data)
    print(categorical_data_encoded)
    
    # Scale the numerical data
    numerical_data_scaled = scaler.transform(numerical_data)
    print(numerical_data_scaled)
    
    # Concatenate the two types of data
    data = np.concatenate([numerical_data_scaled, categorical_data_encoded], axis=1)
    
    # Make prediction
    prediction = model.predict(data)
    
    return {"prediction": prediction[0]}