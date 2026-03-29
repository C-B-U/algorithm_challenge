from sys import stdin
input = stdin.readline

N, M, K, S, T = map(int, input().split())

RIFTS = [ [] for _ in range(N + 1) ]
COURSES = [ [] for _ in range(N + 1) ]

for _ in range(M):
    a, b, t = map(int, input().split())
    if a > b: a, b = b, a
    RIFTS[b].append(a)
    COURSES[a].append((b, t))

# DP [ 리프트 횟수 ] [ 지점 ] = 스키를 탄 최대 시간
dp = [ [ -1 ] * (N + 1) for _ in range(K + 1) ]
dp[0][S] = 0

for rift_c in range(K + 1):

    # 리프트를 rift_count번 탄 상태에서 스키를 타는 경우 계산
    # 스키는 무조건 위에서 아래로만 탈 수 있으므로 순서대로 계산해주면 됨
    for ski_s in range(1, N + 1):
        if dp[rift_c][ski_s] == -1: continue

        for next, dura in COURSES[ski_s]:
            riding = dp[rift_c][ski_s] + dura
            dp[rift_c][next] = max(dp[rift_c][next], riding)

    # 리프트 타기
    if rift_c == K: break
    for ski_s in range(1, N + 1):
        if dp[rift_c][ski_s] == -1: continue
        
        for next in RIFTS[ski_s]:
            dp[rift_c + 1][next] = max(dp[rift_c + 1][next], dp[rift_c][ski_s])
            
print( max( dp[rift_c][T] for rift_c in range(K + 1) ) )