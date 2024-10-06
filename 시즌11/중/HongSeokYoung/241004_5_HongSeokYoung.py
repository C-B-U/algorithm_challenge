# 백준 알고리즘 20937 떡국 문제

from collections import Counter

# 입력 받기
N = int(input())  # 그릇의 개수
sizes = list(map(int, input().split()))  # 각 그릇의 크기

# 각 그릇 크기의 빈도 계산
size_counts = Counter(sizes)

# 가장 많이 등장한 그릇 크기의 빈도를 찾기
max_count = max(size_counts.values())

# 결과 출력
print(max_count)
