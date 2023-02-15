# 26264번: 빅데이터? 정보보호!

N = int(input())
feild = input()  # 문자열을 받아오고
bigdata = feild.count('bigdata')  # 문자열에서 bigdata의 등장 횟수를 카운트
security = feild.count('security')  # 문자열에서 security의 등장 횟수를 카운트

# 문제에 따라서 횟수에 따라 출력을 함
if bigdata > security :
    print('bigdata?')
elif bigdata < security :
    print('security!')
else :
    print('bigdata? security!')
