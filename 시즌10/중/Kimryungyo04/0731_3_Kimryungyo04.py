# 브루트포스로 체크

n = int(input())
if n < 10: print(n); quit()
count = 9

for num in range(10, n + 1):
    
    str_num = str(num)
    common_diff = int(str_num[1]) - int(str_num[0])

    count += 1
    before = int(str_num[0]) - common_diff

    for sub_num in str_num:
        sub_num = int(sub_num)
        if sub_num != (before + common_diff):
            count -= 1
            break
        before = sub_num

print(count)
