import sys
input = sys.stdin.readline

#n은 사람 수 , m은 식당 개수 
n , m = map(int , input().split())

# x는 별점을 저장할 2차원 리스트 
x = []
for i in range(n):
    row = list(map(int , input().split()))
    x.append(row)

max_each_person = [max(row) for row in x]
answer = [0] * m

for z in range(m):
    cnt = 0
    for i in range(n):
        if x[i][z] < max_each_person[i] :
            cnt += 1
    answer[z] = cnt 


print (*answer)
