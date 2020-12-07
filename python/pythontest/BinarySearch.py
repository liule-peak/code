def binary_search(list,value):
    left = 0
    right = len(list) - 1 
    for i in range(left,right):
        mid = int((left + right) / 2)
        if list[mid] == value:
            return mid
        elif list[mid] > value:
            right = mid - 1
        else:
            left = mid + 1
    return None


arr = [1,2,3,4,5,6,7,8,9,10]
print(binary_search(arr,5))