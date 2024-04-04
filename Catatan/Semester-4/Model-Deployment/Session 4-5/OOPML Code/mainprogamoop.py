import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.metrics import classification_report
import numpy as np
from sklearn.model_selection import GridSearchCV
import pickle

class DataHandler:
    def __init__(self, file_path):
        self.file_path = file_path
        self.data = None
        self.input_df = None
        self.output_df = None

    def load_data(self):
        self.data = pd.read_csv(self.file_path)
        
    def create_input_output(self, target_column):
        self.output_df = self.data[target_column]
        self.input_df = self.data.drop(target_column, axis=1)

# ModelHandler Class
class ModelHandler:
    def __init__(self, input_data, output_data):
        self.input_data = input_data
        self.output_data = output_data
        self.createModel()
        self.x_train, self.x_test, self.y_train, self.y_test, self.y_predict = [None] * 5
    
    def checkAgeOutlierWithBox(self,kolom):
        boxplot = self.x_train.boxplot(column=[kolom]) 
        plt.show()
        
    def createMeanFromColumn(self,kolom):
        return np.mean(self.x_train[kolom])
    
    def createModel(self,criteria='gini',maxdepth=6):
         self.model = RandomForestClassifier(criterion=criteria,max_depth=maxdepth)

    def dataConvertToNumeric(self,columns):
        self.x_train[columns] = pd.to_numeric(self.x_train[columns], errors='coerce')
        self.x_test[columns] = pd.to_numeric(self.x_train[columns], errors='coerce')

    def fillingNAWithNumbers(self,columns,number):
        self.x_train[columns].fillna(number, inplace=True)
        self.x_test[columns].fillna(number, inplace=True)
    
    def makePrediction(self):
        self.y_predict = self.model.predict(self.x_test) 
        
    def createReport(self):
        print('\nClassification Report\n')
        print(classification_report(self.y_test, self.y_predict, target_names=['1','2','3','4','5','6']))
            
    def split_data(self, test_size=0.2, random_state=42):
        self.x_train, self.x_test, self.y_train, self.y_test = train_test_split(
            self.input_data, self.output_data, test_size=test_size, random_state=random_state)

    def train_model(self):
        self.model.fit(self.x_train, self.y_train)

    def evaluate_model(self):
        predictions = self.model.predict(self.x_test)
        return accuracy_score(self.y_test, predictions)
    
    def tuningParameter(self):
        parameters = {
            'criterion':['gini', 'entropy', 'log_loss'],
            'max_depth':[2,4,6,8], 
        }
        RFClass = RandomForestClassifier()
        RFClass= GridSearchCV(RFClass ,
                            param_grid = parameters,   # hyperparameters
                            scoring='accuracy',        # metric for scoring
                            cv=5)
        RFClass.fit(self.x_train,self.y_train)
        print("Tuned Hyperparameters :", RFClass.best_params_)
        print("Accuracy :",RFClass.best_score_)
        self.createModel(criteria =RFClass.best_params_['criterion'],maxdepth=RFClass.best_params_['max_depth'])

    def save_model_to_file(self, filename):
        with open(filename, 'wb') as file:  # Open the file in write-binary mode
            pickle.dump(self.model, file)  # Use pickle to write the model to the file



file_path = 'dermatology_database_1.csv'  
data_handler = DataHandler(file_path)
data_handler.load_data()
data_handler.create_input_output('class')
input_df = data_handler.input_df
output_df = data_handler.output_df

model_handler = ModelHandler(input_df, output_df)
model_handler.split_data()
model_handler.dataConvertToNumeric('age')

#Check Outlier
#model_handler.checkAgeOutlierWithBox('age')

age_replace_na = model_handler.createMeanFromColumn('age')
model_handler.fillingNAWithNumbers('age',age_replace_na)

print("Before Tuning Parameter")
model_handler.train_model()
print("Model Accuracy:", model_handler.evaluate_model())
model_handler.makePrediction()
model_handler.createReport()
print("After Tuning Parameter")
model_handler.tuningParameter()
model_handler.train_model()
print("Model Accuracy:", model_handler.evaluate_model())
model_handler.makePrediction()
model_handler.createReport()
model_handler.save_model_to_file('trained_model.pkl') 



