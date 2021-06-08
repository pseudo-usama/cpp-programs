import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.cluster import KMeans
Dataset = pd.read_csv(
    'Mall_Customers.csv', encoding='ANSI')

X = Dataset.values[:, [3, 4]]

wcss = []
for i in range(1, 11):
    kmean = KMeans(n_clusters=i)
    kmean = kmean.fit(X)
    wcss.append(kmean.inertia_)

plt.plot(range(1, 11), wcss)
plt.show()


# Appling K Mean with Right Cluster

kmean = KMeans(n_clusters=5)
y_mean = kmean.fit_predict(X)

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
