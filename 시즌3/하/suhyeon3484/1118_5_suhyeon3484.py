# 1475 : 방 번호

n = input()

ans = [0] * 10

for i in n:
    i = int(i)
    n = int(n)
    
    if i == 6 or i == 9:
        if ans[6] < ans[9]:
            ans[6] += 1
        else:
            ans[9] += 1
    else:
        ans[i] += 1

print(max(ans))