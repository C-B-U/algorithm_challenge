n = int(input())
nums = list(map(int, input().split()))

max_num = nums[0]

for i in range(1, n):
    if nums[i] > max_num:
        max_num = nums[i]

print(max_num)
