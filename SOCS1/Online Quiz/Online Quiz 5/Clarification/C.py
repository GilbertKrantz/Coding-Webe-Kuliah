
N = int(input())
y = 0

for x in range(N) :
    a, b, c = input().split()
    print(a, b, c)

    if ( b > c ) :
        y += 1

print(y)