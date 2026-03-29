n = int(input())

data = list(map(int, input().split()))

add, sub, mul, div = map(int, input().split())

max_value = -1e9
min_value = 1e9

def dfs(i, arr):
    global add, sub, mul, div, max_value, min_value

    if i == n:
        max_value = max(max_value, arr)
        min_value = min(min_value, arr)
    else:
        if add > 0:
            add -= 1
            dfs(i + 1, arr + data[i])
            add += 1
        if sub > 0:
            sub -= 1
            dfs(i + 1, arr - data[i])
            sub += 1
        if mul > 0:
            mul -= 1
            dfs(i + 1, arr * data[i])
            mul += 1
        if div > 0:
            div -= 1
            dfs(i + 1, int(arr / data[i]))
            div += 1

dfs(1, data[0])

print(max_value)
print(min_value)