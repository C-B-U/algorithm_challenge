import sys
input = sys.stdin.readline

N, M = map(int, input().split())

styles = []
sups = []
pre_sup = -1

for _ in range(N):
    style, sup = input().split()
    sup = int(sup)

    if sup == pre_sup:
        continue

    styles.append(style)
    sups.append(sup)
    pre_sup = sup

def binary_search(target):
    left, right = 0, len(sups) - 1
    ans = right

    while left <= right:
        mid = (left + right) // 2

        if sups[mid] >= target:
            ans = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return ans

for _ in range(M):
    power = int(input())
    idx = binary_search(power)
    print(styles[idx])#