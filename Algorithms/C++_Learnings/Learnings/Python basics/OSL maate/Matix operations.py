X = [[12,7,3],
    [4 ,5,6],
    [7 ,8,9]]

Y = [[5,8,1],
    [6,7,3],
    [4,5,9]]

result = [[0,0,0],
          [0,0,0],
          [0,0,0],]

for i in range(len(X[0])):
    for j in range(len(X[0])):
        for k in range(len(X[0])):
            result[i][j] += X[i][k]*Y[k][j]
print(result)
