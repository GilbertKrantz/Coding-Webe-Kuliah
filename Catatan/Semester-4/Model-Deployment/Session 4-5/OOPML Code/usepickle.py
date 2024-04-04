import pickle
import warnings
warnings.filterwarnings('ignore')
def load_model(filename):
    """ Load the trained model from a pickle file. """
    with open(filename, 'rb') as file:
        model = pickle.load(file)
    return model

def predict_with_model(model, user_input):
    """ Make a prediction using the model and user input. """
    prediction = model.predict([user_input])
    return prediction[0]

def main():
    model_filename = 'trained_model.pkl'  # Replace with your model's filename
    model = load_model(model_filename)

    user_input = [2,1,2,3,1,3,0,3,0,0,0,1,0,0,0,1,2,0,2,0,0,0,0,0,2,0,2,3,2,0,0,2,3,26]
    prediction = predict_with_model(model, user_input)
    print(f"The predicted output is: {prediction}")

if __name__ == "__main__":
    main()
