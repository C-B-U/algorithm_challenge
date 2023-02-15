# 빅데이터? 정보보호!

n = int(input())
memo = input()
bigdata = memo.count('bigdata')
security = memo.count('security')

if bigdata < security:
    print("security!")
elif bigdata > security:
    print("bigdata?")
else:
    print("bigdata? security!")