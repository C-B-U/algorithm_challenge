# DP에 모든 부분 문자열을 최대한 압축한 길이를 기록
# DP[i][j]는 string[i:j] 부분 문자열의 최소 길이

# 각 문자열의 최소 길이는 다음 세가지 경우 중 하나
# 1. 기존 문자열 그대로 쓰는 경우 ( len(string) )
# 2. 두 문자열로 분리한 후 각 문자열을 압축한 뒤 연결하는 경우
# 3. 문자열에 주기가 있는 경우 (특정 문자열이 반복되는 경우)

S = input()
N = len(S)
dp = [ [0] * ( N + 1 ) for _ in range(N) ]

# 최소 반복 주기
def min_period_len(sub_str):
    if len(sub_str) <= 1: return len(sub_str)
    
    i = (sub_str + sub_str).find(sub_str, 1, -1)
    return len(sub_str) if i == -1 else i

for L in range(1, N + 1): # 부분문자열 길이
    for i in range(0, N - L + 1): # 시작 인덱스
        j = i + L

        # 1. 가장 짧은 길이를 저장, 초기에는 기본 상태
        best = L

        # 2. 문자열을 두 문자열로 분리한 후 각 문자열의 최소 길이의 합
        for k in range(i + 1, j):
            cand = dp[i][k] + dp[k][j]
            if cand < best:
                best = cand

        # 3. 문자열이 반복되는 경우
        string = S[i:j]
        period = min_period_len(string) # 반복 주기
        if period < L and L % period == 0:
            times = L // period
            cand = 2 + len(str(times)) + dp[i][i + period]
            if cand < best:
                best = cand

        # 4. 해당 구간의 가장 짧은 길이를 기록
        dp[i][j] = best

print(dp[0][N])