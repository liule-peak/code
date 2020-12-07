import struct
import os
import numpy as np
from numpy.core.fromnumeric import _transpose_dispatcher

path='/data/train-images.idx3-ubyte'
kind = train
image_path=os.path.join(path,'%s-images.idx3-ubyte'%kind)
labels_path=os.path.join(path,'%s-labels.idxl-ubyte'%kind)

with open(labels_path,'rb') as labelfile:
    magic,n=struct.unpack('>II',labelfile.read(8))
    labels=np.fromfile(labelfile,dtype=np.uint8)

with open(image_path,'rb') as imagefile:
    magic,num,rows,cols=struct.unpack('>IIII',imagefile.read(16))
    images=np.fromfile(imagefile,dtype=np.uint8).reshape(len(labels),784)

images=images/255

class MnistData(object):

    def __init__(self, absPath, is4Cnn, dataType):
        self.absPath = absPath
        self.is4Cnn = is4Cnn  # True for cnn,False for other nn structures
        self.dataType = dataType
        self.imgs, self.labels = self._load_mnist_data(kind='train')
        self.imgs_v, self.labels_v = self._load_mnist_data(kind='t10k')
        self.sample_range = [i for i in range(len(self.labels))]  # 训练样本范围
        self.sample_range_v = [i for i in range(len(self.labels_v))]  # 验证样本范围

    # 加载mnist
    def _load_mnist_data(self, kind='train'):
        labels_path = os.path.join(self.absPath, '/data/%s-labels.idx1-ubyte' % kind)
        images_path = os.path.join(self.absPath, '/data/%s-images.idx3-ubyte' % kind)

        with open(labels_path, 'rb') as labelfile:
            # 读取前8个bits
            magic, n = struct.unpack('II',labelfile.read(8))
            # 余下的数据读到标签数组中
            labels = np.fromfile(labelfile, dtype=np.uint8)

        with open(images_path, 'rb') as imagefile:
            # 读取前16个bit
            magic, num, rows, cols = struct.unpack('>IIII', imagefile.read(16))
            # 余下数据读到image二维数组中，28*28=784像素的图片共60000张（和标签项数一致）
            # reshape 从原数组创建一个改变尺寸的新数组(28*28图片拉直为784*1的数组)
            # CNN处理的输入则reshape为28*28*1
            if False == self.is4Cnn:
                images_ori = np.fromfile(imagefile, dtype=np.uint8).reshape(len(labels), 784)
            else:
                # 支持多通道，此处通道为1
                images_ori = np.fromfile(imagefile, dtype=np.uint8).reshape(len(labels), 1, 28, 28)
            # 归一化
            images = images_ori / 255
        return images, labels

    # 对训练样本序号随机分组
    def getTrainRanges(self, miniBatchSize):

        rangeAll = self.sample_range
        random.shuffle(rangeAll)
        rngs = [rangeAll[i:i + miniBatchSize] for i in range(0, len(rangeAll), miniBatchSize)]
        return rngs

    # 获取训练样本范围对应的图像和标签
    def getTrainDataByRng(self, rng):

        xs = np.array([self.imgs[sample] for sample in rng], self.dataType)
        values = np.array([self.labels[sample] for sample in rng])
        return xs, values

    # 获取随机验证样本
    def getValData(self, valCapacity):

        samples_v = random.sample(self.sample_range_v, valCapacity)
        #  验证输入 N*28*28
        images_v = np.array([self.imgs_v[sample_v] for sample_v in samples_v], dtype=self.dataType)
        #  正确类别 1*K
        labels_v = np.array([self.labels_v[sample_v] for sample_v in samples_v])

        return images_v, labels_v