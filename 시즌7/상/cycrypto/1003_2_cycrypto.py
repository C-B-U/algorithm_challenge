l, w, h = map(int, input().split())
n = int(input())

cube = sorted([list(map(int, input().split())) for _ in range(n)], reverse=True)

now, ans = 0, 0
for exp, cnt in cube:
    now *= 8
    cur_len = 2 ** exp

    fill = min((l // cur_len) * (w // cur_len) * (h // cur_len) - now, cnt)

    ans += fill
    now += fill

print(ans if now == l * w * h else -1)