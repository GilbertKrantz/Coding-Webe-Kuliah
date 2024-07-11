import httpx

def test_prediction(item):
    response = httpx.post("http://127.0.0.1:8000/predict", json=item)
    return response.json()

# Define the test cases
test_cases = [
    {
        "duration": 120,
        "campaign": 3,
        "pdays": 999,
        "previous": 0,
        "job": "admin.",
        "marital": "married",
        "education": "university.degree",
        "default": "no",
        "housing": "yes",
        "loan": "no",
        "contract": "cellular"
    },
    {
        "duration": 300,
        "campaign": 1,
        "pdays": 999,
        "previous": 1,
        "job": "blue-collar",
        "marital": "single",
        "education": "high.school",
        "default": "no",
        "housing": "no",
        "loan": "yes",
        "contract": "telephone"
    },
    {
        "duration": 50,
        "campaign": 2,
        "pdays": 5,
        "previous": 2,
        "job": "technician",
        "marital": "divorced",
        "education": "basic.9y",
        "default": "yes",
        "housing": "yes",
        "loan": "no",
        "contract": "cellular"
    }
]

# Test the predictions
for i, case in enumerate(test_cases):
    prediction = test_prediction(case)
    print(f"Test Case {i+1}: {prediction}")
