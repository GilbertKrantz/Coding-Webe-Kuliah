
T = int(input())

for i in range(T) :
    N, X = input().split()
    N = int(N)
    X = int(X)
    Y = 0


    if ( X % 2 != 0 and X != 1) :
        X -= 1
    
    if ( N % 2 != 0 and N != 1) :
        N -= 1
    
    if ( X == 1 or X == N) :
        Y = 0
    elif ( X == 2 ) :
        Y = 1
    elif ( X <= N/2) :
        Y = X / 2
    elif ( X >= N/2) :
        Y = (N - X) /2
    print("Case #{}: {}".format(i + 1, round(Y)))