import numpy as np

def maxValue(c, n, w, v):
    flag = np.zeros(n+1)
    for i in range (1,n+1):
        for j in range(c,w[i-1]-1,-1):
            F[j] = max(F[j], F[j - w[i - 1]] + v[i - 1])
            if F[j] > F[j - w[i - 1]] + v[i - 1]:
                flag[i]=0
            else:
                flag[i]=1

    for k in range(1,n+1):
        print(str(int(flag[k]))+" ")
    return F[c]

F = np.arange(0,100)
c = 10
n = 5
w = [2, 2, 6, 5, 4]
v = [6, 3, 5, 4, 6]
print(maxValue(c, n, w, v))
    
