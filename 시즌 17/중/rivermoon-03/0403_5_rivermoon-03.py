import sys
input = sys.stdin.readline

h, n = map(int, input().split())

# c, r, 인덱스
hikari = []
for i in range(n):
    r, c = map(int, input().split())
    hikari.append((c, r, i))

# c 기준 정렬
hikari.sort()

ans = [0] * n
# i는 정렬 순서, j는 원래 인덱스
for i in range(n):
    c, r, j = hikari[i]
    ans[j] = i + 1  # 1번부터 순위 부여

print("YES")
print(*ans)