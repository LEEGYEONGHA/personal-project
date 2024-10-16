# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import numpy as np
# 붓꽃 데이터셋의 경로를 판다스 라이브러리에서 가져와야 하는데, 이것에 대해서는 교수님께 여쭤봐야 할 듯

class Perceptron(object):
    def __init__(selt, eta=0.01, n_iter=50, random_state=1):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state
        
    def fit(self, X, y):
        rgen = np.random.RandomState(self.random_state)
        self.w_ =rgen.normal(loc=0.0, scale=0.01, size=1 + X.shape[1])
        
        self.errors_ = []
        
        for _ in range(self.n_iter):
            errors = 0
            for xi, target in zip(X, y):
                update = self.eta * (target - self.predict(xi))
                self.w_[1:] += update * xi
                self.w_[0] += update
                errors += int(update != 0.0)
            self.errors_.append(errors)
        return self
    
    def net_input(self, X):
        """ 입력 계산 """
        return np.dot(X, self.w_[1:]) + self.w_[0]
    
    def predict(self, X):
        """ 단위 계단 함수를 사용하여 클래스 레이블을 반환한다. """
        return np.where(self.net_input(X) >= 0.0, 1, -1)
    
import pandas as pd

df = pd.read_csv('C:/Users/User/Downloads/dataset_61_iris.csv',
                 header=None,
                 encoding='utf-8')
# 파일 경로가 지정이 안 되어있어서 계속 오류 나는 것 같음...하 인생

y = df.iloc[0:100, 4].values
y = np.where( y== 'Iris-setosa', -1, 1)

X = df.iloc[:100, [0,2]].values

ppn = Perceptron(eta=0.1, n_iter=10)
ppn.fit(X, y)

from matplotlib.colors import ListedColormap

def plot_decision_regions(X, y, classifier, resolution=0.02):
    markers = ('s', 'x', 'o', '^', 'v')
    colors = ('red', 'blue', 'lightgreen', 'gray', 'cyan')
    cmap = ListedColormap(colors[:len(np.unique(y))])
    
    x1_min, x1_max = X[:,0].min() - 1, X[:, 0].max() + 1
    x2_min, x2_max = X[:,1].min() - 1, X[:, 1].max() + 1
    xx1, xx2 = np.meshgrid(np.arange(x1_min, x1_max, resolution),
                               np.arange(x2_min, x2_max, resolution))
    Z = classifier.predict(np.array([xx1.ravel(), xx2.ravel()]).T)
    Z = Z.reshape(xx1.shape)
    plt.contourf(xx1, xx2, Z, alpha=0.3, cmap=cmap)
    plt.xlim(xx1.min(), xx1.max())
    plt.ylim(xx2.min(), xx2.max())
    
    for idx, cl in enumerate(np.unique(y)):
        plt.scatter(x = X[y == cl, 0],
                    y = X[y == cl, 1],
                    alpha = 0.8,
                    c = colors[idx],
                    marker=markers[idx],
                    label=cl,
                    edgecolor='black')
        
plot_decision_regions(X, y, classifier=ppn)
plt.xlabel('seal length [cm]')
plt.ylabel('petal length [cm]')
plt.legend(loc='upper left')
plt.show()


