stu = int(input())
number = input().split()
number = list(map(int, number))
li=[]
for i in range(stu):
    li.insert(number[i], i+1)
li.reverse()
print(*li)