n = int(input())

# 걸리는 시간과 로봇의 번호를 같이 저장
robots = {}
for i in range(n):
    a, b, v = map(int, input().split())
    robots[i+1] = ((a**2 + b**2)**0.5)/v

# 터지는데 걸리는 시간을 기준으로 로봇의 번호를 정렬
distroy_robots = dict(sorted(robots.items(), key=lambda item: item[1]))
distroy_time = list(distroy_robots.keys())

for sequence in distroy_time:
    print(sequence)
