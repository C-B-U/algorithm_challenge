import sys
input = sys.stdin.readline

cnt = 0
cnt_i = 0
n = input().strip()
m = input().strip()

while cnt_i < len(n):
    if n[cnt_i] == m[0]:
        if n[cnt_i:cnt_i+len(m)] == m:
            cnt += 1
            cnt_i += len(m)
        else:
            cnt_i += 1
    else:
        cnt_i += 1

print(cnt)
