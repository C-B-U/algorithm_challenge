# 입력 받기
numbers = [int(input()) for _ in range(9)]

# 최댓값 찾기
max_num = max(numbers)

# 위치 찾기
index = numbers.index(max_num) + 1

# 출력하기
print(max_num)
print(index)
