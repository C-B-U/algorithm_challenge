# 좌표 정렬하기

n = int(input())
lst = []
for i in range(n):
    [a,b] =  list(map(int, input().split()))
    lst.append([a,b])
    
lst.sort(key = lambda x: (x[0], x[1])) # x좌표가 같으면 y좌표로 둘다 오름차순!

for i in lst:
    print(i[0], i[1])