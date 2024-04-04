import pandas as pd
import pickle
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import classification_report

class dataHandler :
    def __init__(self, file_path):
        self.file_path = file_path
        self.data = None
        self.input_df = None
        self.output_df = None
    
    def load_data(self):
        self.data = pd.read_csv(self.file_path, sep=';')
    
    def create_input_output(self, target_column):
        self.input_df = self.data.drop(target_column, axis=1)
        self.output_df = self.data[target_column]
        
class modelHandler:
    train_encode={"Gender": {"Male":1,"Female" :0}, "Ever_Married":{"Yes":1, "No":0}, "Graduated":{"Yes":1, "No":0}}
    test_encode={"Gender": {"Male":1,"Female" :0}, "Ever_Married":{"Yes":1, "No":0}, "Graduated":{"Yes":1, "No":0}}
    
    def __init__(self, input_data, output_data):
        self.input_data = input_data
        self.output_data = output_data
        self.createModel()
        self.x_train, self.x_test, self.y_train, self.y_test, self.y_predict = [None] * 5
    
    def checkMissingValue(self, columns):
        print(f"Input data missing value is:\n {self.x_train[columns].isnull().sum()}")

    @staticmethod
    def checkVariableTypes(x_train):
        categorical_col = []
        numerical_col = []
        for col in x_train.columns:
            if x_train[col].dtype == 'object':
                categorical_col.append(col)
            else:
                numerical_col.append(col)
        return categorical_col, numerical_col
    
    def missingValueImpute(self):
        categorical_col, numerical_col = self.checkVariableTypes(self.x_train)
        for col in categorical_col:
            self.x_train[col].fillna(self.x_train[col].mode()[0], inplace=True)
            self.x_test[col].fillna(self.x_train[col].mode()[0], inplace=True)
        
        for col in numerical_col:
            self.x_train[col].fillna(self.x_train[col].mean(), inplace=True)
            self.x_test[col].fillna(self.x_train[col].mean(), inplace=True)
    
    def categoricalEncoding(self):
        self.x_train = self.x_train.replace(modelHandler.train_encode)
        self.x_test = self.x_test.replace(modelHandler.test_encode)
    
    def oneHotEncoding(self):
        x=self.x_train[['Profession','Spending_Score']]
        encoder = OneHotEncoder()
        train_data=pd.DataFrame(encoder.fit_transform(x).toarray(),columns=encoder.get_feature_names_out())
        self.x_train=self.x_train.reset_index()
        x_train_enc=pd.concat([self.x_train,train_data], axis=1)
        
        x=self.x_test[['Profession','Spending_Score']]
        test_data=pd.DataFrame(encoder.transform(x).toarray(),columns=encoder.get_feature_names_out())
        self.x_test=self.x_test.reset_index()
        x_test_enc=pd.concat([self.x_test,test_data], axis=1)
        
        self.x_train=x_train_enc[['Gender', 'Ever_Married', 'Age', 'Graduated', 
                     'Work_Experience', 'Family_Size','Profession_Artist', 
                     'Profession_Doctor', 'Profession_Engineer',
                     'Profession_Entertainment', 'Profession_Executive',
                     'Profession_Healthcare', 'Profession_Homemaker', 
                     'Profession_Lawyer','Profession_Marketing', 
                     'Spending_Score_Average', 'Spending_Score_High',
                     'Spending_Score_Low' ]]
        
        self.x_test=x_test_enc[['Gender', 'Ever_Married', 'Age', 'Graduated', 
                     'Work_Experience', 'Family_Size','Profession_Artist', 
                     'Profession_Doctor', 'Profession_Engineer',
                     'Profession_Entertainment', 'Profession_Executive',
                     'Profession_Healthcare', 'Profession_Homemaker', 
                     'Profession_Lawyer','Profession_Marketing', 
                     'Spending_Score_Average', 'Spending_Score_High',
                     'Spending_Score_Low' ]]
        
    def createModel(self,criteria='gini',maxdepth=6):
        self.model = DecisionTreeClassifier(criterion=criteria,max_depth=maxdepth)
        
    def split_data(self, test_size=0.2, random_state=42):
        self.x_train, self.x_test, self.y_train, self.y_test = train_test_split(
            self.input_data, self.output_data, test_size=test_size, random_state=random_state)
    
    def train_model(self):
        self.model.fit(self.x_train, self.y_train)
    
    def makePrediction(self):
        self.y_predict = self.model.predict(self.x_test)
    
    def createReport(self):
        print('\nClassification Report\n')
        print(classification_report(self.y_test, self.y_predict, target_names=['A', 'B', 'C','D']))
        
    def save_model_to_file(self, filename):
        with open(filename, 'wb') as file:  # Open the file in write-binary mode
            pickle.dump(self.model, file)  # Use pickle to write the model to the file
        


filepath = "GSLC_Forum 5/user_segmentation.csv"
data_Handler = dataHandler(filepath)
data_Handler.load_data()
data_Handler.data.head()
data_Handler.create_input_output('Segmentation')
input_df = data_Handler.input_df
output_df = data_Handler.output_df

model_Handler = modelHandler(input_df, output_df)
model_Handler.split_data()
model_Handler.missingValueImpute()
model_Handler.categoricalEncoding()
model_Handler.oneHotEncoding()
model_Handler.train_model()
model_Handler.makePrediction()
model_Handler.createReport()
model_Handler.save_model_to_file('model.pkl')

        
        
        
    
        