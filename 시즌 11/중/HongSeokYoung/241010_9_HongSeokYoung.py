# 백준알고리즘 15723 'n단 논법' 문제

# 입력 받기
n = int(input())
relations = {}

# 관계 입력 받기
for _ in range(n):
    a, _, b = input().split()
    if a not in relations:
        relations[a] = []
    relations[a].append(b)

# 플로이드-와샬 알고리즘 적용
for k in relations:
    for i in relations:
        if k in relations[i]:
            for j in relations[k]:
                if j not in relations[i]:
                    relations[i].append(j)

# 쿼리 처리
m = int(input())
for _ in range(m):
    a, _, b = input().split()
    if b in relations.get(a, []):
        print("T")
    else:
        print("F")
