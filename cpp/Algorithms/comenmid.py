def searchMid(a,b):
    if len(a) != len(b):
        return -1
    s1 = 0
    e1 = len(a) - 1
    s2 = 0
    e2 = len(b) - 1
    while s1<=e1 and s2<=e2:
        mid1 = int((s1+e1)/2)
        mid2 = int((s2+e2)/2)
        if a[mid1] == b[mid2]:
            return a[mid1]
        
        if a[mid1] < b[mid2]:
            s1 = mid1 + 1
            e2 = mid2
        else:
            s2 = mid2 + 1
            e1 = mid1
        
    if a[s1] < b[s2]:
        return a[s1]
    else:
        return b[s2]

a=[11, 13, 15, 17, 19]
b=[2, 4, 10, 15, 20]

result = searchMid(a,b)

print(result)

