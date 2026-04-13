n, m = map(int, input().split())
a = list(map(int, input().split()))

safe_time = sum(a) - n

if safe_time >= m:
    print("DIMI")
else:
    print("OUT")
