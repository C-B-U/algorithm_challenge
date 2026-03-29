def solve(n: int, d: int) -> int | None:
    if n == 1:
        return 8 * d
    if n == 5:
        return 4 + 8 * d
    if n == 3:
        return 2 + 4 * d
    if n == 2:
        return (1 + 8 * (d // 2)) if d % 2 == 0 else (3 + 4 * d)
    if n == 4:
        return (3 + 4 * d) if d % 2 == 0 else (5 + 8 * (d // 2))

n,d = int(input()), int(input())
print(solve(n, d))