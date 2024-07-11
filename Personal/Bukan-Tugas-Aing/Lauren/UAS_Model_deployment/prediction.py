import numpy as np
import pandas as pd
from fastapi import FastAPI
import pickle
from pydantic import BaseModel

app = FastAPI()

# Load the model
model_package = pickle.load(open('model_package.pkl', 'rb'))

class Model_unpackager():
    def __init__(self, model_package):
        self.model = model_package['model']
        self.scaler = model_package['scaler']
        self.encoder = model_package['encoder']
        
class user_data(BaseModel):
    age: int
    job: str
    marital: str
    education: str
    default: str
    housing: str
    loan: str
    contact: str
    duration: int
    campaign: int
    previous: int
    poutcome: str
    
@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.post("/predict")
def predict(data: user_data):
    model = Model_unpackager(model_package)
    
    data = data.model_dump()
    
    numerical_data = [[data['age'], data['duration'], data['campaign'], data['previous']]]
    categorical_data = [[data['job'], data['marital'], data['education'], data['default'], data['housing'], data['loan'], data['contact'], data['poutcome']]]
    
    numerical_data = pd.DataFrame(numerical_data, columns=['age', 'duration', 'campaign', 'previous'])
    categorical_data = pd.DataFrame(categorical_data, columns=['job', 'marital', 'education', 'default', 'housing', 'loan', 'contact', 'poutcome'])
    
    numerical_data = model.scaler.transform(numerical_data)
    categorical_data = model.encoder.transform(categorical_data)
    
    data = np.concatenate([numerical_data, categorical_data], axis=1)
    
    prediction = model.model.predict(data)
    
    return {'prediction': prediction[0]}