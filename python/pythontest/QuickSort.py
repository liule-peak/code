def partition(list,low,high):
    pivot = list[low]
    while low < high:
        while low < high and list[high] >= pivot:
            high = high - 1
        list[low] = list[high]
        while low < high and list[low] <= pivot:
            low = low + 1
        list[high] = list[low]

    list[low] = pivot
    return low

def quicksort(list,low,high):
    if low < high:
        pivotpos = partition(list,low,high)
        quicksort(list, low, pivotpos - 1)
        quicksort(list, pivotpos + 1, high)

arr = [8, 7, 6, 5, 4, 3, 2, 1]
quicksort(arr,0,len(arr)-1)
print(arr)

