from fastapi import FastAPI
from pydantic import BaseModel
import joblib
import numpy as np
import pandas as pd

app = FastAPI()
# Load the machine learning model
model = joblib.load('RF_iris.pkl')

class IrisSpecies(BaseModel):
    sepal_length: float
    sepal_width: float
    petal_length: float
    petal_width: float

@app.get("/")
def read_root():
       return {"message": "Welcome to the ML Model API"}

@app.post('/predict')

def predict(iris: IrisSpecies):
    data = iris.model_dump()
    features = [[data['sepal_length'], data['sepal_width'], data['petal_length'], data['petal_width']]]
    prediction = model.predict(features)
    return {'prediction': prediction[0]}


