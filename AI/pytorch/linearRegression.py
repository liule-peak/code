import torch
from torch.autograd import Variable
import matplotlib.pyplot as plt

x=Variable(torch.ones(2,2),requires_grad=True)
x=Variable(torch.linspace(0,100).type(torch.FloatTensor))
rand=Variable(torch.randn(100))*10

y=x+rand

x_train=x[:-10]
x_test=x[-10:]
y_train=y[:-10]
y_test=y[-10:]

plt.figure(figsize=(10,8))
plt.plot(x_train.data.numpy(),y_train.data.numpy(),'o')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()

a=Variable(torch.rand(1),requires_grad=True)
b=Variable(torch.rand(1),requires_grad=True)


learning_rate=0.0001

for i in range(1000):
    predictions = a.expand_as(x_train)*x_train + b.expand_as(x_train)
    loss = torch.mean((predictions-y_train)**2)
    print('loss:',loss)
    loss.backward()
    a.data.add_(-learning_rate*a.grad.data)
    b.data.add_(-learning_rate*b.grad.data)
    a.grad.data.zero_()
    b.grad.data.zero_()

x_data=x_train.data.numpy()
plt.figure(figsize=(10,7))
xplot,=plt.plot(x_data,y_train.data.numpy(),'o')
yplot,=plt.plot(x_data,a.data.numpy()*x_data+b.data.numpy())
plt.xlabel('X')
plt.ylabel('Y')
str1 = str(a.data.numpy()[0])+'x + ' + str(b.data.numpy()[0])
plt.legend([xplot,yplot],['Data',str1])
plt.show()