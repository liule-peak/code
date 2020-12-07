# 数量词
# * 匹配*前面一个字符 0次或着无限多次
# + 匹配+前面一个字符 1次或着无限多次
# ？ 匹配0次或者1次
import re
a = 'python 1111pythonnjavanpytho678php'

r = re.findall('python*',a)
#贪婪 与 非贪婪
print(r)

b = re.findall('python{1,2}?',a)
print(b)


#边界匹配
qq ='10000000000001'
# 4-8位
r = re.findall('^\d{4,8}$',qq)
print(qq)

c='pythonpythonpython'  #[] 或关系 #() 且关系
r=re.findall('(python){3}(JS)',a)
print(r)