w, h, n = map(int, input().split())

if n % 2 == 0:
    result = (n - 2) / 4.0
else:
    result = ((n - 1) * (n - 1)) / (4.0 * n)

result *= 2 * h

print(f"{result:.6f}")
