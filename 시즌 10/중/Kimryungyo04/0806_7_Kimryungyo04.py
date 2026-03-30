# 들을 수 있는 수업의 수를 배열에 저장해두고 수업의 수가 부족한 경우 듣지 못하는 학생 수를 1 늘린다

class_list = [ 0 ] * 1000001
n = int(input())

absent_students = 0

for class_num in map(int, input().split()):
    class_list[class_num] += 1

for class_num in map(int, input().split()):
    if class_list[class_num] == 0:
        absent_students += 1
    else:
        class_list[class_num] -= 1

print(absent_students)
