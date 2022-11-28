
N = int(input())

A = [int(y) for y in input().split()]

B = []

for i in range(len(A)) :
    if (A[i-1] >= A[i]) :
        B.append(A[i-1])

element = B[0]

B.append(element)

del B[0]

print(*B)