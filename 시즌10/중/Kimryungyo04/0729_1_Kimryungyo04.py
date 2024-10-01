from sys import stdin
input = lambda: stdin.readline().rstrip()

n, m = map(int, input().split())
count = 0

original = [ list(map(int, input())) for _ in range(n) ]
changed = [ list(map(int, input())) for _ in range(n) ]

# 엣지 케이스 처리
if n < 3 or m < 3:
    print(0 if original == changed else -1)
    quit()

# 모든 블록을 돌아가며 값이 다르면 뒤집기
# 값이 다르나 뒤집을 수 없는 경우 -1 출력 후 프로그램 종료
for r in range(n):
    for c in range(m):

        if original[r][c] != changed[r][c]:

            if r >= n - 2 or c >= m - 2: 
                print(-1); quit()

            for y in range(r, r + 3):
                for x in range(c, c + 3):
                    value = original[y][x]
                    original[y][x] = 1 if value == 0 else 0

            count += 1

print(count)
