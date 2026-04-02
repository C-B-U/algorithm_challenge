# 상->하 좌->우로 체크판 형식으로 체크한다
# 단, 칸의 수(NM)가 짝수인 경우 (1, 1)부터, 홀수인 경우 (1, 2)부터 체크판을 찌른다

from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
st_col = (N * M) % 2

for r in range(0, N):
    for c in range(st_col, M, 2):
        print(f"? {r+1} {c+1}", flush=True)
        if int(input()) == 1:
            quit()
    st_col ^= 1