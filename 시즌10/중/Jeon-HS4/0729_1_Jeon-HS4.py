n, m = map(int, input().split())

A = [list(map(int, list(input().strip()))) for _ in range(n)]
B = [list(map(int, list(input().strip()))) for _ in range(n)]
    
def flip(i, j):
  for x in range(i, i + 3):
      for y in range(j, j + 3):
          A[x][y] = 1 - A[x][y]

count = 0
if (n < 3 or m < 3) and A != B:
    count = -1
else:
    for r in range(n - 2):
        for c in range(m - 2):
            if A[r][c] != B[r][c]:
                count += 1
                flip(r, c)


if A != B:
    count = -1

print(count)
