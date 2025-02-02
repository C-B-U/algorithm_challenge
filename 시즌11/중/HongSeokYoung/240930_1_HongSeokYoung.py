# 백준 알고리즘 23028번 '5학년은 다니기 싫어요' 문제

N, A, B = map(int, input().split())

check_list = []

rest_session = 8 - N
total_credit = 0
total_major_credit = 0

for _ in range(10):
    X, Y = map(int, input().split())
    check_list.append((X, Y))

for i in range(rest_session):
    major_credit = check_list[i][0]
    non_major_credit = check_list[i][1]
    
    if major_credit > 6:
        major_credit = 6
    
    total_major_credit += major_credit * 3
    
    credit = major_credit + non_major_credit
    if credit > 6:
        credit = 6
    
    total_credit += credit * 3

if total_major_credit > 66 - A and total_credit > 130 - B:
    print("Nice")
else:
    print("Nae ga wae")