def bubblesort(list):
    for i in range(len(list)-1):
        exchange = False
        for j in range(0,len(list)-i-1):
            if list[j] > list[j+1]:
                list[j],list[j+1] = list[j+1],list[j]
                exchange = True
        
        if not exchange:
            return 

arr = [3,1,5,4,2]
bubblesort(arr)
print(arr)
            