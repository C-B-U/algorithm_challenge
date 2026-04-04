import sys
input = sys.stdin.readline

n, m = map(int, input().split())

grades = []
scores = []

for _ in range(n):
    g, s = input().split()
    grades.append(g)
    scores.append(int(s))

for _ in range(m):
    power = int(input())
    
    # 이진 탐색
    start = 0
    end = n - 1
    result_idx = 0
    
    while start <= end:
        mid = (start + end) // 2
        if scores[mid] >= power:
            result_idx = mid
            end = mid - 1
        else:
            start = mid + 1
            
    print(grades[result_idx])