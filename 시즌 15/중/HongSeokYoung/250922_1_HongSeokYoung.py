# 백준 알고리즘 24499번 'blobyum' https://www.acmicpc.net/problem/24499

N, K = map(int, input().split())
arr = list(map(int, input().split()))

# 원형 처리를 위해 배열 2배 확장
arr = arr * 2

# 처음 K개 합
window_sum = sum(arr[:K])
max_sum = window_sum

# 슬라이딩 윈도우
for i in range(K, N+K-1):  # 최대 N개 구간만 보면 됨
    window_sum += arr[i] - arr[i-K]
    max_sum = max(max_sum, window_sum)

print(max_sum)