import numpy as np


def kgraph(graph):
    n = graph.shape[0]
    length = np.full((n+1), F)
    path = np.full((n+1), -1)
    length[0] = 0
    path[0] = -1
    for j in range(1, n+1):
        for i in range(j-1, -1, -1):
            print(i,j)
            if length[i]+graph[i][j] < length[j]:
                length[j] = length[i]+graph[i][j]
                path[j] = i

    print(length[n-1])
    print("n-1")
    i=n-1
    while path[i] >= 0:
        print("->"+str(path[i]))
        i = path[i]


F = 1000
graph = np.array([[0, 4, 2, 3, F, F, F, F, F, F],
                  [F, 0, F, F, 9, 8, F, F, F, F],
                  [F, F, 0, F, 6, 7, 8, F, F, F],
                  [F, F, F, 0, F, 4, 7, F, F, F],
                  [F, F, F, F, 0, F, F, 5, 6, F],
                  [F, F, F, F, F, 0, F, 8, 6, F],
                  [F, F, F, F, F, F, 0, 6, 5, F],
                  [F, F, F, F, F, F, F, 0, F, 7],
                  [F, F, F, F, F, F, F, F, 0, 3]])

kgraph(graph)

