import sys
input = sys.stdin.readline

nums = []
for _ in range(10):
    nums.append(int(input()))

print(nums[0] - sum(nums[1:]))
