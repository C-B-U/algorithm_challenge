# 백준 알고리즘 1205번 '등수 구하기' 문제
import sys

# 입력 받기
N, S, P = map(int, sys.stdin.readline().split())

if N > 0:
    scores = list(map(int, sys.stdin.readline().split()))
else:
    scores = []

# 새로운 점수가 몇 등인지 찾기
rank = 1  # 1등부터 시작
for i in range(N):
    if scores[i] > S:
        rank += 1
    else:
        break  # 같거나 낮은 점수를 만나면 그 위치가 등수

# 랭킹이 꽉 찼을 때, 들어갈 수 있는지 확인
if N == P and (scores[-1] >= S):  
    print(-1)  # 마지막 점수보다 낮거나 같으면 진입 불가
else:
    print(rank)