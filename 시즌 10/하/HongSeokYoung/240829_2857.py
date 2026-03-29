# 백준 알고리즘 2857 FBI 문제

count = 0
check = 0

for i in range(5):
    name = input()
    count+=1
    if 'FBI' in name:
        check = 1
        print(count)

if check == 0:
    print("HE GOT AWAY!")