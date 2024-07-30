# 브루트포스로 체크

n = int(input())
if n < 100: print(n); quit()
count = 99

for num in range(100, n + 1):
    nums = list(map(int, str(num)))

    if nums[0] - nums[1] == nums[1] - nums[2]:
        count += 1

print(count)
