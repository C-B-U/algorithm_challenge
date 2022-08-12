from sys import stdin

n = int(stdin.readline())
nums = []
for _ in range(n):
    nums.extend(map(int, stdin.readline().split(' ')))
    nums = sorted(nums, reverse=True)[:n]

print(nums[-1])
