def InsertSort(list):
    for i in range(1,len(list)):
        if list[i] < list[i-1]:
            temp = list[i]
            j = i -1
            while j>=0 and list[j]>temp:
                list[j+1] = list[j]
                j = j-1
            list[j+1] = temp

arr = [5,4,3,2,1]
InsertSort(arr)
print(arr)