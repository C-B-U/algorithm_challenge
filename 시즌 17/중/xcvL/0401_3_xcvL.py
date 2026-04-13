N, m = map(int, input().split())

act1 = N
act2 = N // 2
act3 = (N + 1) // 2
act4 = (N - 1) // 3 + 1

ans = 1

if act1 <= m:
    ans += 1

if N > 1:
    if act2 <= m:
        ans += 1
    if act3 <= m:
        ans += 1

if N > 2:
    if act4 <= m:
        ans += 1
    if act1 + act4 <= m:
        ans += 1
    if act2 + act4 <= m:
        ans += 1
    if act3 + act4 <= m:
        ans += 1

print(ans)