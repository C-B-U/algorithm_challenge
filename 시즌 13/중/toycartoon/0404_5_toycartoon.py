from math import inf


n = int(input())
a = list(map(int, input().split()))
op = list(map(int, input().split()))

ans_min = inf
ans_max = -inf

def bt(num, plus, minus, mul, div):
    global ans_max, ans_min
    
    if plus == minus == mul == div == 0:
        if num[0] > ans_max:
            ans_max = num[0]
        if num[0] < ans_min:
            ans_min = num[0]

        return

    if plus > 0:
        bt([num[0] + num[1]] + num[2:], plus - 1, minus, mul, div)
    if minus > 0:
        bt([num[0] - num[1]] + num[2:], plus, minus - 1, mul, div)
    if mul > 0:
        bt([num[0] * num[1]] + num[2:], plus, minus, mul - 1, div)
    if div > 0:
        x = num[0]
        y = num[1]

        s = x // y
        if x < 0 and y > 0:
            s = -(-x // y)
            
        bt([s] + num[2:], plus, minus, mul, div - 1)


bt(a, *op)
print(ans_max)
print(ans_min)
