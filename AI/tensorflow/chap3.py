from numpy.core.fromnumeric import reshape
import tensorflow as tf
import numpy as np
from matplotlib import pyplot as plt

N = 100

w_true = 5
b_true = 2
noise_scale = .1
x_np = np.random.rand(N, 1)
noise = np.random.normal(scale=noise_scale, size=(N, 1))
y_np = np, reshape(w_true*x_np + b_true + noise, (-1))

plt.title("toy")
plt.xlabel("hi")
plt.ylabel("hell")
plt.scatter(x_np,y_np)
plt.show()
