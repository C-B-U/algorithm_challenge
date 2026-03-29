# 백준 알고리즘 2605 줄 세우기 문제

N = int(input())

pickNumber = list(map(int, input().split()))

student_list = []

for i in range(N):
    index = i - pickNumber[i]
    student_list.insert(index, i + 1)

print(' '.join(map(str, student_list)))