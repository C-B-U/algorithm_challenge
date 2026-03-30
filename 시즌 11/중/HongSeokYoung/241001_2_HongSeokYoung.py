# 백준 알고리즘 23038번 '박스 그림 문자' 문제

MAX = 301

class Block:
    def __init__(self):
        self.arr = [['' for _ in range(3)] for _ in range(3)]

block = [[Block() for _ in range(MAX)] for _ in range(MAX)]

def func(r, c, n, m):
    if r != 1 and block[r - 1][c].arr[2][1] == '#':
        block[r][c].arr[0][1] = '#'
    if c != 1 and block[r][c - 1].arr[1][2] == '#':
        block[r][c].arr[1][0] = '#'
    if r != n and block[r + 1][c].arr[0][1] == '#':
        block[r][c].arr[2][1] = '#'
    if c != m and block[r][c + 1].arr[1][0] == '#':
        block[r][c].arr[1][2] = '#'

    flag = False
    for i in range(3):
        for j in range(3):
            if block[r][c].arr[i][j] == '#':
                flag = True
    if flag:
        block[r][c].arr[1][1] = '#'

def main():
    n, m = map(int, input().split())
    
    for i in range(3 * n):
        line = input().strip()
        for j in range(3 * m):
            block[i // 3 + 1][j // 3 + 1].arr[i % 3][j % 3] = line[j]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if (i + j) % 2 == 1:
                func(i, j, n, m)

    for i in range(3 * n):
        for j in range(3 * m):
            print(block[i // 3 + 1][j // 3 + 1].arr[i % 3][j % 3], end='')
        print()

if __name__ == "__main__":
    main()