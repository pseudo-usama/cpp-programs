from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
import numpy as np


class Classfication_Algo():
    @classmethod
    # ! Decision Tree Classifier
    def Decision_Tree_Train(self, X_train, y_train, X_test):
        Classifier = DecisionTreeClassifier(criterion='entropy', random_state=100, max_depth=3, min_samples_leaf=5)
        Classifier = Classifier.fit(X_train, y_train)
        return Classifier.predict(X_test)

    @classmethod
    # ! Random Forest Classifier
    def Random_Forest_Train(self, X_train, y_train, X_test):
        Classifier = RandomForestClassifier(n_estimators=100)
        Classifier = Classifier.fit(X_train, y_train)
        return Classifier.predict(X_test)

    @classmethod
    # ! Naive Bayes Model
    def Naive_Bayes_Train(self, X_train, y_train, X_test):
        Classifier = GaussianNB()
        Classifier = Classifier.fit(X_train, y_train)
        return Classifier.predict(X_test)
    
    @classmethod
    def Naive_Bayes_without_libraries_Train(self, X_train, y_train, X_test):
        naive_bayes = naive_bayes_without_libraries()
        modal = naive_bayes.training(X_train, y_train)
        return naive_bayes.predict(X_test, modal)

    @classmethod
    # ! K-Nearest Neighbour
    def K_Nearest_Neighbour(self, X_train, y_train, X_test):
        Classifier = KNeighborsClassifier()
        Classifier = Classifier.fit(X_train, y_train)
        return Classifier.predict(X_test)


class naive_bayes_without_libraries():
    def training(self, x_train, y_train):
        x_train_possibilities = {}
        y_train_possibilities = {}
    
        # Here we count every possible value for every column in x_train
        for col in range(x_train.shape[1]):
            x_train_possibilities[col] = {}
            for row in range(x_train.shape[0]):
                if x_train[row, col] in x_train_possibilities[col]:
                    x_train_possibilities[col][x_train[row, col]] += 1
                else:
                    x_train_possibilities[col][x_train[row, col]] = 1
    
        # Here we count every possible value for y_train
        for row in range(y_train.shape[0]):
            if y_train[row] in y_train_possibilities:
                y_train_possibilities[y_train[row]] += 1
            else:
                y_train_possibilities[y_train[row]] = 1
    
        # Now we create multiple data frames having all possibilities of decision column
        datasets = {}
        for key in y_train_possibilities:
            datasets[key] = x_train[y_train == key]
    
        # Now we calculate the probability of every possible value in each column
        model = {}
        i = -1
        for col in x_train_possibilities:
            i += 1
            model[col] = {}
            for val in x_train_possibilities[col]:
                model[col][val] = {}
                for decision_key in y_train_possibilities:
                    model[col][val][decision_key] = len(datasets[decision_key][:, i][datasets[decision_key][:, i] == val]) / y_train_possibilities[decision_key]
    
        return model
    
    def predict(self, x_test, modal):
        results = np.array([])
        for row in x_test:
            probabilities = {}
            for decision in modal[0]['1']:
                probabilities[decision] = 1
                col = -1
                for val in row:
                    col += 1
                    probabilities[decision] *= modal[col][val][decision]
    
            results = np.append(results, max(probabilities.items(), key=lambda x:x[1])[0])
    
        return results
