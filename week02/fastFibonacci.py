''' fastFibonacci.py
    소프트웨어학부 20213043 이세현
  # test case input
    3
    0
    29
    2147483647
  # test case output
    0
    229
    973
'''

mat = [[1,1], [1,0]]

def multiply(a, b):
    r00 = a[0][0] * b[0][0] + a[0][1] * b[1][0]
    r01 = a[0][0] * b[0][1] + a[0][1] * b[1][1]
    r10 = a[1][0] * b[0][0] + a[1][1] * b[1][0]
    r11 = a[1][0] * b[0][1] + a[1][1] * b[1][1]
    return [[r00%1000, r01%1000], [r10%1000, r11%1000]]


def fastFibo(n):
    if(n <= 1):
        return mat
    elif(n%2 == 1):
        y = fastFibo((n-1)/2)
        return multiply(mat, multiply(y, y))
    else:
        y = fastFibo(n/2)
        return multiply(y, y)


numTestCases = int(input())

for i in range(numTestCases):
    testcase = int(input())
    print(fastFibo(testcase+1)[1][1])