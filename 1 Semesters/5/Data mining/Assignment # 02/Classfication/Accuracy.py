from sklearn.metrics import confusion_matrix, accuracy_score, classification_report
import matplotlib.pyplot as plt


class Accuracy():
    @classmethod
    def Accracy_Confusion_Matrix(self, y_test, y_pred):
        Confusion_Matrix = confusion_matrix(y_test, y_pred)
        print('Confusion Matrixs\n', Confusion_Matrix)

        left = [1, 2, 3, 4]
        height = [Confusion_Matrix[0][0], Confusion_Matrix[0][1], Confusion_Matrix[1][0], Confusion_Matrix[0][0]]
        labels = ['True -ve', 'False +ve', 'False -ve', 'True +ve']

        plt.bar(left, height, tick_label=labels, width=0.8, color=['green', 'red', 'red', 'green'])
        plt.xlabel('Possibilities in Matrix')
        plt.ylabel('No. of records')
        plt.title('Confusion Matrix')
        plt.show()

    @classmethod
    def Accuracy_Score(self, y_test, y_pred, classifier_name):
        accuracy = accuracy_score(y_test, y_pred) * 100
        print('Accuracy of ' + classifier_name + ' : ', accuracy, '%', end='\n\n')
        print(classification_report(y_test, y_pred))

        plt.pie([accuracy, 100 - accuracy], labels=['Accurate', 'Inaccurate'], colors=['green', 'red'], autopct='%.2f', radius=2, shadow=True)
        plt.title('Accuracy of ' + classifier_name)
        plt.show()
