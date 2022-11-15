#입력
N = int(input())

num_list = list(map(int, input().split())) 

#출력
for i in sorted(list(set(num_list))): #set으로 중복 방지, sorted로 정렬
    print(i, end = ' ')
