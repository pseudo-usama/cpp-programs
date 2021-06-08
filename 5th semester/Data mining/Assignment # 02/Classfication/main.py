from sklearn.model_selection import train_test_split
import pandas as pd

# Importing Local Classes
from Classifiers import Classfication_Algo
from Accuracy import Accuracy


# Creating objects
Classifier = Classfication_Algo()
Accuracy_Obj = Accuracy()


Dataset = pd.read_csv('Pre-processed.csv', sep=',', header=None, encoding='ANSI')
X = Dataset.iloc[1:, 1:6].values
y = Dataset.iloc[1:, 6].values
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=100)


def Decision_Tree():
    Decision_Tree_Predict = Classifier.Decision_Tree_Train(X_train, y_train, X_test)
    Accuracy_Obj.Accuracy_Score(y_test, Decision_Tree_Predict, 'Decision Tree')
    Accuracy_Obj.Accracy_Confusion_Matrix(y_test, Decision_Tree_Predict)


def Random_Forest():
    Randam_Forest_Predict = Classifier.Random_Forest_Train(X_train, y_train, X_test)
    Accuracy_Obj.Accuracy_Score(y_test, Randam_Forest_Predict, 'Random Forest')
    Accuracy_Obj.Accracy_Confusion_Matrix(y_test, Randam_Forest_Predict)


def Naive_Bayes():
    Naive_Bayes_Predict = Classifier.Naive_Bayes_Train(X_train, y_train, X_test)
    Accuracy_Obj.Accuracy_Score(y_test, Naive_Bayes_Predict, 'Naive Bayes')
    Accuracy_Obj.Accracy_Confusion_Matrix(y_test, Naive_Bayes_Predict)
    
def Naive_Bayes_without_libraries():
    Naive_Bayes_Predict = Classifier.Naive_Bayes_without_libraries_Train(X_train, y_train, X_test)
    Accuracy_Obj.Accuracy_Score(y_test, Naive_Bayes_Predict, 'Naive Bayes(without Libraries)')
    Accuracy_Obj.Accracy_Confusion_Matrix(y_test, Naive_Bayes_Predict)


def K_Nearest_Neighbours():
    K_Nearest_Neighbour_Predict = Classifier.K_Nearest_Neighbour(X_train, y_train, X_test)
    Accuracy_Obj.Accuracy_Score(y_test, K_Nearest_Neighbour_Predict, 'K Nearest Neighbour')
    Accuracy_Obj.Accracy_Confusion_Matrix(y_test, K_Nearest_Neighbour_Predict)


if __name__ == "__main__":
    print(end='\n\n\n\n')
    Decision_Tree()
    
    print(end='\n\n\n\n')
    Random_Forest()
    
    print(end='\n\n\n\n')
    Naive_Bayes()
    
    print(end='\n\n\n\n')
    Naive_Bayes_without_libraries()
    
    print(end='\n\n\n\n')
    K_Nearest_Neighbours()
