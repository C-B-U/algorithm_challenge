import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
MAX = 51

def get_dp(idx1, idx2, idx3):
    if idx2 == n - 1:
        return 0
    if dp[idx1][idx2][idx3] != -1:
        return dp[idx1][idx2][idx3]

    ret = 0
    for i in range(idx3 + arr[idx2] + 1):
        if idx1 >= i:
            ret = max(ret, get_dp(idx1 - i, idx2 + 1, i) + (power[idx2 + 1] - power[idx2]) * i)

    dp[idx1][idx2][idx3] = ret
    return ret

def max_character_power(n, arr, power, d):
    result = sum(arr[i] * power[i] for i in range(n))
    return result + get_dp(d, 0, 0)

n = int(input())
arr = list(map(int, input().split()))
power = list(map(int, input().split()))
d = int(input())
dp = [[[-1] * 105 for _ in range(MAX)] for _ in range(105)]
print(max_character_power(n, arr, power, d))
