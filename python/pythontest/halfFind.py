def BinarySearch(A, k):
    h = 0
    r = len(A) - 1
    while(h <= r):
        mid = int((h+r)/2)
        if A[mid] == k:
            return mid
        elif A[mid] > k:
            r = mid - 1
        else:
            h = mid + 1


A = [7, 14, 18,  21,  23,  29, 31, 35,  38,  42, 46, 49, 52]
print(BinarySearch(A,14))