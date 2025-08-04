# 백준 알고리즘 6549번 '히스토그램에서 가장 큰 직사각형' https://www.acmicpc.net/problem/6549

import sys
input = sys.stdin.readline

while True:
    arr = list(map(int, input().split()))
    n = arr[0]
    if n == 0:
        break
    
    heights = arr[1:]
    stack = []
    max_area = 0

    for i in range(n):
        # 스택이 비지 않고 현재 막대가 스택 top의 높이보다 낮으면 pop
        while stack and heights[stack[-1]] > heights[i]:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)

    # 남은 막대 처리
    while stack:
        height = heights[stack.pop()]
        width = n if not stack else n - stack[-1] - 1
        max_area = max(max_area, height * width)

    print(max_area)