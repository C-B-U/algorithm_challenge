#백준 알고리즘 1474번 '밑 줄'문제
import sys
input = sys.stdin.readline

# 입력 처리
N, M = map(int, input().strip().split())
words = [input().strip() for _ in range(N)]

# 전체 단어 길이 계산
total_length = sum(len(word) for word in words)

# 추가해야 할 밑줄 개수
total_underscores = M - total_length
gap = N - 1  # 단어 사이의 간격 개수
quotient, remain = divmod(total_underscores, gap)  # 기본 밑줄 개수, 추가 밑줄 개수

# 결과 문자열 구성
result = words[0]
for i in range(1, N):
    extra = 1 if words[i][0].islower() and remain > 0 or (words[i][0].isupper() and i + remain > gap) else 0
    if extra:
        remain -= 1
    result += "_" * (quotient + extra) + words[i]

# 출력
print(result)