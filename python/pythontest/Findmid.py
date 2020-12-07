def FindMid(A,B):
    if len(A) != len(B):
        return ;
    else:
        ha = 0
        ra = len(A) - 1
        hb = 0
        rb = len(B) - 1
        ma=0
        mb=0
        while ha<ra and hb<rb:
            ma = int((ha+ra)/2)
            mb = int((hb+rb)/2)
            if A[ma] == B[mb]:
                return A[ma]
            elif A[ma]<B[mb]:
                ha = ma
                rb = mb 
            else:
                hb = mb 
                ra = ma  
        
        return min(A[ma],B[mb])

A = [11, 13, 15, 17, 19]
B = [2, 4, 10, 15, 20]
print(FindMid(A,B))
