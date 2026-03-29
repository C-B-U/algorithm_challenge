from sys import stdin

n = int(input())
stw = [0]*n
max_len = -1

for i in range(n):  # 입력
    stw[i] = int(stdin.readline())
stw.sort(reverse=1)     # 정렬

for i in range(n-2):    # 가장 긴 둘레의 삼각형 탐색
    if stw[i] < stw[i+1] + stw[i+2]:
        max_len = stw[i] + stw[i+1] + stw[i+2]
        break   # 발견 했으니 퇴장

print(max_len)
