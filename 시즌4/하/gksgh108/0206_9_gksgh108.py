N = int(input())
memo = input()
data = 0
alpha = 0
for i in range(N):
    if memo[alpha]=='s':
        data += 1
        alpha+=8
    else:
        data -= 1
        alpha+=7

if data>0:
    print("security!")
elif data<0:
    print("bigdata?")
else:
    print("bigdata? security!")
