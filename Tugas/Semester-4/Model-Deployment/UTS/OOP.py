import pandas as pd
import pickle as pk

from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
from sklearn.preprocessing import StandardScaler, OneHotEncoder



class dataHandler:
    def __init__(self, filepath):
        self.filepath = filepath
        self.data = None
        self.input_df = None
        self.output_df = None
        
    def load_data(self):
        self.data = pd.read_csv(self.filepath)
        
    def drop_irrelevant_columns(self, columns):
        self.data.drop(columns, axis=1, inplace=True)
    
    def create_input_output(self, target_column):
        self.input_df = self.data.drop(columns=[target_column], axis=1)
        self.output_df = self.data[target_column]
        
        
class modelHandler:
    categoricSurnameDict = {'Very Prevalen': [], 'Prevalent': [], 'A bit Prevalen': [], 'Not Prevalen': [], 'Very Not Prevalen': []}
    
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
            self.x_train[col].fillna(self.x_train[col].median(), inplace=True)
            self.x_test[col].fillna(self.x_train[col].median(), inplace=True)
            
    def categoricalEncoding(self):
        for surname, count in self.input_data['Surname'].value_counts().items():
            if count >= 100:
                modelHandler.categoricSurnameDict['Very Prevalen'].append(surname)
            elif count >= 50:
                modelHandler.categoricSurnameDict['Prevalent'].append(surname)
            elif count >= 25:
                modelHandler.categoricSurnameDict['A bit Prevalen'].append(surname)
            elif count >= 10:
                modelHandler.categoricSurnameDict['Not Prevalen'].append(surname)
            else:
                modelHandler.categoricSurnameDict['Very Not Prevalen'].append(surname)
        
        self.input_data['Surname Prevalency'] = self.input_data['Surname'].apply(lambda x: 'Very Prevalen' if x in modelHandler.categoricSurnameDict['Very Prevalen'] else 'Prevalent' if x in modelHandler.categoricSurnameDict['Prevalent'] else 'A bit Prevalen' if x in modelHandler.categoricSurnameDict['A bit Prevalen'] else 'Not Prevalen' if x in modelHandler.categoricSurnameDict['Not Prevalen'] else 'Very Not Prevalen')
        
        self.input_data.drop('Surname', axis=1, inplace=True)
        
    def oneHotEncoding(self):
        encoder = OneHotEncoder(handle_unknown='infrequent_if_exist')
        encoded_x_train = self.x_train[['Geography', 'Gender', 'Surname Prevalency']]
        encoded_train = pd.DataFrame(encoder.fit_transform(encoded_x_train).toarray(), columns=encoder.get_feature_names_out())
        # Join the encoded data with the rest of the training data
        self.x_train = self.x_train.drop(columns=['Geography', 'Gender', 'Surname Prevalency'], axis=1).reset_index()
        self.x_train = pd.concat([self.x_train, encoded_train], axis=1).drop(columns=['index'], axis=1)
        self.y_train.reset_index(inplace=True, drop=True)
        
        encoded_x_test = self.x_test[['Geography', 'Gender', 'Surname Prevalency']]
        encoded_test = pd.DataFrame(encoder.transform(encoded_x_test).toarray(), columns=encoder.get_feature_names_out())
        # Join the encoded data with the rest of the training data
        self.x_test = self.x_test.drop(columns=['Geography', 'Gender', 'Surname Prevalency'], axis=1).reset_index()
        self.x_test = pd.concat([self.x_test, encoded_test], axis=1).drop(columns=['index'], axis=1)
        self.y_test.reset_index(inplace=True, drop=True)
        
    def featureScaling(self):
        scaler = StandardScaler()
        numeric_col = ['CreditScore', 'Balance', 'EstimatedSalary', 'Age']
        self.x_train[numeric_col] = scaler.fit_transform(self.x_train[numeric_col])
        self.x_test[numeric_col] = scaler.transform(self.x_test[numeric_col])
        
    def splitData(self, test_size=0.3, random_state=42):
        self.x_train, self.x_test, self.y_train, self.y_test = train_test_split(self.input_data, self.output_data, test_size=test_size, random_state=random_state)
        
    def createModel(self, random_state=42, n_estimators=100, max_depth=30, min_samples_split=2, min_samples_leaf=10, criterion='gini'):
        self.model = RandomForestClassifier(random_state=random_state, n_estimators=n_estimators, max_depth=max_depth, min_samples_split=min_samples_split, min_samples_leaf=min_samples_leaf, criterion=criterion)
    
    def trainModel(self):
        self.model.fit(self.x_train, self.y_train)
    
    def predictModel(self):
        self.y_predict = self.model.predict(self.x_test)
        
    def createReport(self):
        print('\nClassification Report\n')
        print(classification_report(self.y_test, self.y_predict))
        
    def save_model_to_file(self, filename):
        with open(filename, 'wb') as file:  # Open the file in write-binary mode
            pk.dump(self.model, file)  # Use pickle to write the model to the file
        
    
filepath = "data_C.csv"
data_handler = dataHandler(filepath)
data_handler.load_data()
print(data_handler.data.head())
data_handler.drop_irrelevant_columns(['Unnamed: 0', 'id', 'CustomerId'])
data_handler.create_input_output('churn')
input_df = data_handler.input_df
output_df = data_handler.output_df

model_handler = modelHandler(input_df, output_df)
model_handler.categoricalEncoding()
model_handler.splitData()
model_handler.missingValueImpute()
model_handler.oneHotEncoding()
model_handler.featureScaling()
model_handler.trainModel()
model_handler.predictModel()
model_handler.createReport()
model_handler.save_model_to_file('model.pkl')
    