testCase = int(input("Input Number of Test Cases : "))


for i in range(testCase) : 
    matrixSize = int(input("Input Matrix Size : "))
    matrix1 = [[0 for x in range(matrixSize)] for y in range(matrixSize)]
    matrix2 = [[0 for x in range(matrixSize)] for y in range(matrixSize)]
    matrix3 = [[0 for x in range(matrixSize)] for y in range(matrixSize)]
    result1 = [[0 for x in range(matrixSize)] for y in range(matrixSize)]
    result2 = [[0 for x in range(matrixSize)] for y in range(matrixSize)]
    

    for k in range(matrixSize) :
        matrix1[k] = list(map(int, input().split()))
    for k in range(matrixSize) :
        matrix2[k] = list(map(int, input().split()))
    for k in range(matrixSize) :
        matrix2[k] = list(map(int, input().split()))

# iterate throught rows of matrix 1
    for j in range(len(matrix1)):
   # iterate through columns of matriks 2
        for k in range(len(matrix2[0])):
       # iterate through rows of matriks 2
            for l in range(len(matrix2)):
                result1[i][j] += matrix1[i][k] * matrix2[k][j]

# iterate throught rows of result 1
    for j in range(len(result1)):
   # iterate through columns of matriks 3
        for k in range(len(matrix3[0])):
       # iterate through rows of matriks 3
            for l in range(len(matrix3)):
                result2[i][j] += result1[i][k] * matrix3[k][j]

    print(result1)

    
