# [ 풀이 ]
# 실제 키 값이 아니라 남아있는 숫자들 중에서 몇 번째인지(=순위)가 핵심
# 따라서 값 자체를 다루지 않고, 순위를 기반으로 경우의 수를 계산
# 
# DP 정의 : DP[길이][마지막 학생의 순위][다음 비교 방향]

MOD = 1000000
N = int(input())
if N == 1: print(1); quit()

# dp[길이][마지막 학생의 순위][다음 비교 방향]
dp = [[[0, 0] for _ in range(N + 2)] for _ in range(N + 2)]

# 초기값 설정
dp[1][1][0] = 1
dp[1][1][1] = 1

for i in range(1, N):
    for d in (0, 1):
        arr = [0] * (i + 1)
        run = 0
        for k in range(1, i + 1):
            run = (run + dp[i][k][d]) % MOD
            arr[k] = run
        total = arr[i]

        for next_j in range(1, i + 2):
            if d == 0:
                ways = arr[next_j - 1]
            else:
                ways = (total - arr[next_j - 1]) % MOD

            dp[i + 1][next_j][1 - d] = (dp[i + 1][next_j][1 - d] + ways) % MOD

answer = 0
for j in range(1, N + 1):
    answer = (answer + dp[N][j][0] + dp[N][j][1]) % MOD

print(answer)
