import sys
input = sys.stdin.readline

result = []
n, m, t = map(int, input().split())

if t < n and t < m:
    print(f"0 {t}") # 시간이 부족하여 콜라만 마시기
    exit(0)

for coke in range(0, t):
    flag = False
    target = t - coke

    for tow in range(target//n, -1, -1): 
        bul = (target - (tow*n)) // m

        if ((bul * m) + (tow*n)) == target:
            result.append(((bul+tow), coke))
            flag = True
        
    if flag == True:
        break

result.sort()
cnt, cok = result.pop(-1)
print(cnt, end=" ")
print(cok)