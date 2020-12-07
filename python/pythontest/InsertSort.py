def insertsort(list):
    for i in range(1,len(list)):
        temp = list[i]
        j = i-1
        while j>=0 and list[j]>temp:
            list[j+1] = list[j]
            j = j-1
        list[j+1] = temp
        print(arr)

arr = [5,4,3,2,1]
insertsort(arr)