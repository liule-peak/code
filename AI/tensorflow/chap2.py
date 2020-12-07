import tensorflow as tf

with tf.compat.v1.Session() as sess:
    a = tf.zeros((2, 3))   # 全0，2阶张量
    print(a.eval())
    print(type(a))

    r = tf.range(1, 5, 1)  # 1-4，1阶张量
    print(type(r))
    print(r.eval())

    d = tf.linalg.tensor_diag(r)  # 2阶对角张量
    print(d.eval())

    b = tf.eye(4)  # 2阶全1对角张量
    print(b.eval())

    a = tf.ones((2, 3))  # 2阶全1张量 2*3
    print(a.eval())

    b = tf.ones((3, 4))  # 2阶全1张量 3*4
    print(b.eval())

    c = tf.matmul(a, b)  # 张量乘法 2*4
    print(c.eval())
    a = tf.ones((2, 2), dtype=tf.int32)
    print(a.eval())

    print(type(a))  # 2阶全1张量
    print(type(a.eval()))  # numpy.ndarray类型
    print(a.eval().dtype)  # 内容类型int32
    b = tf.cast(a, dtype=float)  # 内容类型强转
    print(b.eval().dtype)

    a = tf.random.normal((2, 2), mean=0, stddev=1)  # 用随机法向分量抽样一个张量
    print(a.eval(), a.eval().dtype)

    print(tf.compat.v1.get_default_graph)  # Tensorflow图

    a = tf.ones((2, 2))
    c = a*a
    b = tf.matmul(a, a)
    print(c.eval)  # 数字乘法
    print(b.eval())  # 张量乘法

    print(sess.run(b))  # sess 会话机制，将储存计算内容

    a = tf.Variable(tf.ones((2, 2)))  # Tensorflow变量
    print(sess.run(a.assign(tf.zeros((2, 2)))))  # 变量初始化
    print(sess.run(a))
