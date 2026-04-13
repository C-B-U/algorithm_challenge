n, g, k = map(int, input().split(" "))

e = []
acu_sum_e = []
acu_sum_sl_e = []
non_e = []

for i in range(n):
    s, l, o = map(int, input().split(" "))
    if o == 0:
        e.append((s, l))
    else:
        non_e.append((s, l))

if len(e) != 0:
    e.sort(key = lambda x: x[1], reverse=True)
    acu_sum_e.append(e[0][0])
    acu_sum_sl_e.append(e[0][0]*e[0][1])
    for i in range(len(e)-1):
        acu_sum_e.append(acu_sum_e[i] + e[i+1][0])
        acu_sum_sl_e.append(acu_sum_sl_e[i] + e[i+1][0]*e[i+1][1])

# print(e)
# print(acu_sum_e)
# print(acu_sum_sl_e)

non_e.sort(key = lambda x: x[1], reverse=True)
# non_e_tree = [(-1, [])]
# for i in range(len(non_e)):
#     target = (i, [])
#     index = len(non_e_tree)
#     non_e_tree.append(target)

# print(non_e)

def check(day):
    result = 0
    if len(e) != 0:
        d1 = findindex(day, e)
        # print("d1", d1)
        if d1 != -1:
            result += acu_sum_e[d1] + (acu_sum_e[len(e)-1] - acu_sum_e[d1]) * day - (acu_sum_sl_e[len(e) - 1] - acu_sum_sl_e[d1])
        else:
            result += acu_sum_e[len(e)-1] * day - acu_sum_sl_e[len(e) - 1]
    # print(result)
    if len(non_e) != 0:
        d2 = findindex(day, non_e)
        cal = [(v[0] if v[1] >= day else v[0]*(day - v[1])) for v in non_e]
        cal.sort()
        if k != 0:
            cal = cal[:-k]
        for i in cal:
            # print(i)
            result += i

    # print(result)
    if result > g:
        return False
    return True

def findindex(day, e):
    start = 0
    end = len(e)-1

    if len(e) == 0:
        return -1

    while start < end:
        mid = (end + start) // 2
        if e[mid][1] < day: # 날짜 지남
            end = mid - 1
            continue
        elif e[mid][1] >= day:
            start = mid + 1

    if end == -1:
        return -1
    if e[end][1] < day:
        return end - 1
    else:
        return end



sx, ex = 0, 10000000000

while sx < ex:
    mid = (sx + ex) // 2
    # print(sx, mid, ex)
    if check(mid):
        sx = mid + 1
    else:
        ex = mid - 1

if check(sx):
    print(sx)
else:
    print(sx-1)
