import pickle
import pandas as pd
import numpy as np
from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

model = pickle.load(open('logistic_regression_model.pkl', 'rb'))

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
    
def scaler(data):
    scaler = pickle.load(open('scaler.pkl', 'rb'))
    data = scaler.transform(data)
    return data

def encoder(data):
    encoder = pickle.load(open('encoder.pkl', 'rb'))
    data = encoder.transform(data)
    return data.toarray()

@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.post("/predict")
def predict(data: user_data):
    data = data.model_dump()
    
    numerical_data = [[data['age'], data['duration'], data['campaign'], data['previous']]]
    categorical_data = [[data['job'], data['marital'], data['education'], data['default'], data['housing'], data['loan'], data['contact'], data['poutcome']]]
    
    numerical_data = pd.DataFrame(numerical_data, columns=['age', 'duration', 'campaign', 'previous'])
    categorical_data = pd.DataFrame(categorical_data, columns=['job', 'marital', 'education', 'default', 'housing', 'loan', 'contact', 'poutcome'])
    
    numerical_data = scaler(numerical_data)
    categorical_data = encoder(categorical_data)
    
    data = np.concatenate([numerical_data, categorical_data], axis=1)
    
    prediction = model.predict(data)
    
    return {'prediction': prediction[0]}
    