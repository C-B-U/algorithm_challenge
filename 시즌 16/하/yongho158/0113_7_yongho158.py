import sys
input = sys.stdin.readline

x , c , k = map(int , input().split())
student_have_seat = [0] * (x + 1) 
seat_list = [0] * (c + 1)

input_list = []

for i in range(k) :
    row = list(map(int , input().split()))
    input_list.append(row) 


input_list.sort(key = lambda row : row[0]) 

for t, s, n in input_list:
    if seat_list [s] != 0:
        continue
    
    old = student_have_seat[n]
    if old != 0:
        seat_list[old] = 0

    student_have_seat[n] = s
    seat_list[s] = n

for i in range(1 , x + 1):
    if student_have_seat[i] != 0:
        print(i , student_have_seat[i])

