import numpy as np
from numpy.core.fromnumeric import shape

a1 = np.random.randint(0, 100, size=(1, 6))
print(a1)
print("a1[:,1]", a1[:, 1])

a = np.arange(1, 11)
print("a = ", a)

print("a[3:7] = ", a[3:7])
print("a[1::2] = ", a[1::2])
print("a[1::3] = ", a[1::3])
print("a[:-6:-1] = ", a[:-6:-1])

print("a[:-6:1] = ", a[:-6:1])
print("a[:-6] = ", a[:-6])


a = np.random.randint(10, size=(3, 5))
print("a = \n", a)

print("a[1, :] = ", a[1, :])
print("a[::-1, 1] = ", a[::-1, 1])

a1 = np.zeros(shape=(3, 5))
a2 = a1[1, 1:4]
print(a2)
a2[2] = 99
print("a1 = \n", a1)
print("a2 = \n", a2)

a = np.arange(1,10)
b=a.reshape((3,3))
print(a)
print(b)
print(a.shape)

a=np.arange(10)
print("a=",a)
print("a.shape",a.shape)

a1=a[np.newaxis,:]
print("a1=",a1)

print("a1.shape",a1.shape)

a2=a[:,np.newaxis]
print("a2=",a2)

print("a2.shape",a2.shape)

a1=np.arange(5)
a2=np.arange(5,10)
a3=np.concatenate([a1,a2])

print("a3=",a3)





