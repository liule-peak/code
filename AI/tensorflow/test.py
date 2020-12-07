from sklearn import linear_model
import matplotlib.pyplot as plt

reg = linear_model.LinearRegression()
x = [[0, 0], [1, 1], [2, 2]]
y = [[0], [1], [2]]
reg.fit(x, y)

print(reg.coef_)

plt.scatter(x, y,  color='black')
plt.plot(x, y, color='blue', linewidth=3)

plt.xticks(color='red')
plt.yticks(color='blue')

plt.show()
