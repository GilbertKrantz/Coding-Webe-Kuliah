from fastapi import FastAPI
import pandas as pd
import numpy as np
import pickle
from pydantic import BaseModel

app = FastAPI()

# Load the model, scaler, and encoder
model = pickle.load(open('model.pkl', 'rb'))
scaler = pickle.load(open('scaler.pkl', 'rb'))
encoder = pickle.load(open('encoder.pkl', 'rb'))

# Define the request body
class Item(BaseModel):
    age: int
    job: str
    marital: str
    education: str
    default: str
    housing: str
    loan: str
    contact: str
    month: str
    day_of_week: str
    duration: int
    campaign: int
    previous: int
    poutcome: str
    
@app.post("/predict")
def predict(data: Item):
    data = data.model_dump()
    
    # Transform the data
    data_num = [[data['age'], data['duration'], data['campaign'], data['previous']]]
    data_num = scaler.transform(data_num)
    
    data_cat = [[data['job'], data['marital'], data['education'], data['default'], data['housing'], data['loan'], data['contact'], data['month'], data['day_of_week'],data['poutcome']]]
    data_cat = encoder.transform(data_cat)
    
    data = np.concatenate([data_num, data_cat], axis=1)
    
    # Make the prediction
    prediction = model.predict(data)
    return {'prediction': prediction[0]}
