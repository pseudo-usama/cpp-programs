from sklearn.cluster import AgglomerativeClustering
import matplotlib.pyplot as plt
import scipy.cluster.hierarchy as sch
import numpy as np
import pandas as pd

Dataset = pd.read_csv(
    'Mall_Customers.csv')

X = Dataset.values[:, [3, 4]]

dendgram = sch.dendrogram(sch.linkage(X, method='ward'))

hc = AgglomerativeClustering(n_clusters=5, linkage='ward')
plt.show()
y_pred = hc.fit_predict(X)
y_mean = y_pred

# Visualization of Data
plt.scatter(X[y_mean == 0, 0], X[y_mean == 0, 1],
            s=10, c='red', label='Cluster 1')
plt.scatter(X[y_mean == 1, 0], X[y_mean == 1, 1],
            s=10, c='green', label='Cluster 2')
plt.scatter(X[y_mean == 2, 0], X[y_mean == 2, 1],
            s=10, c='blue', label='Cluster 3')
plt.scatter(X[y_mean == 3, 0], X[y_mean == 3, 1],
            s=10, c='limegreen', label='Cluster 4')
plt.scatter(X[y_mean == 4, 0], X[y_mean == 4, 1],
            s=10, c='pink', label='Cluster 5')
plt.show()
