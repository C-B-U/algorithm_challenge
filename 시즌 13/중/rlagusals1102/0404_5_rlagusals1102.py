from math import inf

n, arr = int(input()), list(map(int, input().split()))
ops = tuple(map(int, input().split()))

max_res, min_res = -inf, inf

stack: list[tuple[int, int, tuple[int, int, int, int]]] = [(1, arr[0], ops)]

ops_funcs: list[callable] = [
    lambda a, b: a + b,
    lambda a, b: a - b,
    lambda a, b: a * b,
    lambda a, b: -(-a // b) if a < 0 else a // b
]

while stack:
    idx: int
    curr: int
    cnt: tuple[int, int, int, int]

    idx, curr, cnt = stack.pop()

    if idx == n:
        max_res = max(max_res, curr)
        min_res = min(min_res, curr)
        continue

    num = arr[idx]
    for i, func in enumerate(ops_funcs):
        if cnt[i] > 0:
            new_ops = cnt[:i] + (cnt[i] - 1,) + cnt[i + 1:]
            new_val = func(curr, num)
            stack.append((idx + 1, new_val, new_ops))

print(f"{max_res}\n{min_res}")