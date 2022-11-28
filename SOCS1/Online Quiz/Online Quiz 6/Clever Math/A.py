
T = int(input())

for i in range(T) :
    A,B = list(map(int,input().split()))
    
    A = [int(x) for x in str(A)]
    B = [int(x) for x in str(B)]
    C = A
    
    if len(A) >= len(B) :
        for j in range(len(B)) :
            C[j] = A[j] + B[j]
            if C[j] >= 10 :
                C[j] -= 10
    else :
        for j in range(len(A)) :
            C[j] = A[j] + B[j]
            if C[j] >= 10 :
                C[j] -= 10
        
    C = [str(y) for y in C]
    res = int("".join(reversed(C)))
    
    print("Case #{}: {}\n".format(i + 1, res))