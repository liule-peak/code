# To add a new cell, type '
# To add a new markdown cell, type  [markdown]'
#from IPython import get_ipython

import torch
import torch.nn as nn
from torch.autograd import Variable
import torch.optim as optim
import torch.nn.functional as F


import torchvision.datasets as dsets
import torchvision.transforms as transforms


import matplotlib.pyplot as plt
import numpy as np


#get_ipython().run_line_magic('matplotlib', 'inline')


device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')


image_size = 28 # the size of image is 28*28
num_classes = 10 # the number of all classes
num_epochs = 20 # the number of all epoches
batch_size = 64 # a mini batch,64 images
learning_rate=0.001


train_dataset = dsets.MNIST(root = './data',
                            train=True,
                            transform=transforms.ToTensor(),
                            download=True)


test_dataset = dsets.MNIST(root='./data',
                            train=False,
                            transform=transforms.ToTensor())


train_loader = torch.utils.data.DataLoader(dataset=train_dataset,
                                            batch_size=batch_size,
                                            shuffle=True)


indices = range(len(test_dataset))
indices_val = indices[:5000]
indices_test = indices[5000:]


sampler_val = torch.utils.data.sampler.SubsetRandomSampler(indices_val)
sampler_test = torch.utils.data.sampler.SubsetRandomSampler(indices_test)


validation_loader = torch.utils.data.DataLoader(dataset = test_dataset,
                                                batch_size = batch_size,
                                                shuffle = False,
                                                sampler = sampler_val)
test_loader = torch.utils.data.DataLoader(dataset = test_dataset,
                                          batch_size = batch_size,
                                          shuffle= False,
                                          sampler=sampler_test)                                                


class ConvNet(nn.Module):
    def __init__(self,num_classes=10):
        super(ConvNet, self).__init__()
        self.layer1 = nn.Sequential(
            nn.Conv2d(1,16,kernel_size=5,stride=1,padding=2),
            nn.BatchNorm2d(16),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2,stride=2)
        )
        self.layer2 = nn.Sequential(
            nn.Conv2d(16,32,kernel_size=5,stride=1,padding=2),
            nn.BatchNorm2d(32),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2,stride=2)
        )
        self.fc = nn.Linear(7*7*32,num_classes)
    
    def forward(self,x):
        out = self.layer1(x)
        out = self.layer2(out)
        out = out.reshape(out.size(0),-1)
        out = self.fc(out)
        return out


model = ConvNet(num_classes).to(device)


criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(),lr=learning_rate)


total_step = len(train_loader)
for epoch in range(num_epochs):
    for i,(images,labels) in enumerate(train_loader):
        images = images.to(device)
        labels = labels.to(device)

        outputs =model(images)
        loss = criterion(outputs,labels)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        if (i+1)%100 == 0:
            print('Epoch [{}/{}], Step [{}/{}], Loss:{:.4f}'.format(epoch+1,num_epochs,i+1,total_step,loss.item()))


model.eval()


with torch.no_grad():
    correct = 0
    total = 0
    for images,labels in test_loader:
        images = images.to(device)
        labels = labels.to(device)
        outputs = model(images)
        _, predicted = torch.max(outputs.data,1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

    print('Test Accuracy of the model on the 10000 test images: {} %'.format(100*correct/total))


torch.save(model.state_dict(),'model.ckpt')


