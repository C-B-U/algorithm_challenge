# 나누기

N = int(input())
F = int(input())
front = N // 100
answer = front * 100

while answer % F != 0: # 나눠떨어질때까지
    answer += 1

print(str(answer)[-2:])