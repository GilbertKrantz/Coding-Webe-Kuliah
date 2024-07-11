from fastapi import FastAPI
from pydantic import BaseModel
import joblib
import numpy as np
import pandas as pd 

app = FastAPI()
# Load the machine learning model
model_scaler = joblib.load('model_and_scaler.pkl')
model = model_scaler['model']
scaler = model_scaler['scaler']

class maintenance_failure(BaseModel):
    Air_temperature: float
    Rotatianal_speed: float
    Torque: float
    Tool_wear: float

@app.get("/")
def read_root():
       return {"message": "Welcome to the ML Model API"}

@app.post('/predict')

def predict(maintenance: maintenance_failure):
    data = maintenance.model_dump()
    features = [[data['Air_temperature'], data['Rotatianal_speed'], data['Torque'], data['Tool_wear']]]
    print(features)
    scaled_features = scaler.transform(features)
    prediction = model.predict(scaled_features)
    return {'prediction': prediction[0]}