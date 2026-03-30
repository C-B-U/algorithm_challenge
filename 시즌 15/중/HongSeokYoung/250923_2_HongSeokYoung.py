# 백준 알고리즘 14501번 '퇴사' https://www.acmicpc.net/problem/14501

N = int(input())
T, P = [], []
for _ in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

dp = [0] * (N+1)  # dp[i] = i번째 날부터의 최대 이익

for i in range(N-1, -1, -1):
    if i + T[i] <= N:  # 상담 가능
        dp[i] = max(P[i] + dp[i + T[i]], dp[i+1])
    else:  # 상담 불가능
        dp[i] = dp[i+1]

print(dp[0])