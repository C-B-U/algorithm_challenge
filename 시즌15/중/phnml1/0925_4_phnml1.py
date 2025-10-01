import sys
input = sys.stdin.readline

n = int(input().rstrip())
nums = list(map(int, input().rstrip().split()))
ops = list(map(int, input().rstrip().split()))
MAX = -1e9
MIN = 1e9

def bt(val, depth, add, minus, multi, div):
    global MAX, MIN
    if depth == n:
        MAX = max(val, MAX)
        MIN = min(val, MIN)
        return
    if add > 0: bt(val + nums[depth], depth + 1, add - 1, minus, multi, div)
    if minus > 0: bt(val - nums[depth], depth + 1, add, minus - 1, multi, div)
    if multi > 0: bt(val * nums[depth], depth + 1, add, minus, multi - 1, div)
    if div > 0: bt(int(val / nums[depth]), depth + 1, add, minus, multi, div - 1)

bt(nums[0], 1, ops[0], ops[1], ops[2], ops[3])
print(MAX)
print(MIN)