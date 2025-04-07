# 백준 알고리즘 3048번 '개미' https://www.acmicpc.net/problem/3048

n1, n2 = map(int, input().split())
group1 = list(input().strip())[::-1]  # 왼쪽에서 오는 group1을 뒤집어서 배치
group2 = list(input().strip())       # 오른쪽에서 오는 group2는 그대로

ants = group1 + group2
t = int(input())

for _ in range(t):
    i = 0
    while i < len(ants) - 1:
        if ants[i] in group1 and ants[i + 1] in group2:
            ants[i], ants[i + 1] = ants[i + 1], ants[i]
            i += 2  # 교환 후 다음 칸은 건너뜀
        else:
            i += 1

print("".join(ants))