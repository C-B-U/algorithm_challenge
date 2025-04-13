download = play = min_start = 0

for _ in range(int(input())):
    d, v = map(int, input().split())
    download += v
    min_start = max(min_start, download - play)
    play += d

print(min_start)
