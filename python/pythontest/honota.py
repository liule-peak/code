import numpy as np

def hanota(arr):
    m = arr.shape[0]
    n = arr.shape[1]
    addsum = np.zeros((m+1, n+1))

    for i in range(n):
        addsum[m-1][i] = arr[m-1][i]

    for i in range(m-1,-1,-1):
        for j in range(n-1,-1,-1):
            addsum[i][j] = max(addsum[i+1][j]+arr[i][j],
                               addsum[i+1][j+1]+arr[i][j])

    return addsum[0][0]


arr = np.array([[8, 0, 0, 0, 0], [12, 15, 0, 0, 0], [
               3, 9, 6, 0, 0], [8, 10, 5, 12, 0], [16, 4, 18, 10, 9]])

print(arr.shape)
print(hanota(arr))
