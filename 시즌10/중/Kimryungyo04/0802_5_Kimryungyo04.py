W, H, N = map(int, input().split())
diff = H / N
length = 0

for x in range(1, N):
    height = diff * x
    if x < (N / 2): length -= height
    elif x > (N / 2): length += height

print(f"{length * 2:.6f}")
