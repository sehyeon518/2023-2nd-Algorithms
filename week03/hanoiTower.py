''' hanoiTower.py
    소프트웨어학부 20213043 이세현
  # test case input
    3
    3 5
    1 1
    64 18446744073709551615
  # test case output
    2 1
    1 3
    2 3
'''

def hanoi_tower(n, a, b, c, target):
    if n <= 1:
        print(a, c)
        return
    t = 2 ** (n-1)
    if t > target:
        hanoi_tower(n-1, a, c, b, target)
    elif t == target:
        print(a, c)
        return
    else:
        hanoi_tower(n-1, b, a, c, target - t);

def solve_hanoi_tower():
    num_disks = 3;
    hanoi_tower(num_disks, 1, 2, 3)

numTestCases = int(input())

for i in range(numTestCases):
    n, k = map(int, input().split())  # n개의 원반, k 번째로 옮겨질 원반의 source 기둥 번호와 target 기둥 번호
    hanoi_tower(n, 1, 2, 3, k)