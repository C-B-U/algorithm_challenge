# 해당되는 n*n 칸이 모두 같은 숫자가 올 때까지 재귀적으로 함수를 호출하는 방식으로 사용

# 입력한 배열에서 좌측 상단의 숫자와 모두 같은지 확인
def check_same(x, y, n, image):
    is_same = True
    value = image[x][y]
    for i in range(x, x + n):
        if not is_same:  # 만약 다른 숫자가 검출되면 반복문 탈출
            break
        for j in range(y, y + n):  # x, y축에 해당하는 모든 칸을 방문하면서 
            if image[i][j] != value:  # 만약 좌상단의 숫자와 다른 경우가 발생하면
                is_same = False  # 확인을 위해 is_same을 False로 바꾸고 이후의 칸 방문을 생략
                break
    if is_same:  # 모두 같은 숫자로 이뤄져 있으면 해당 숫자를 반환
        return value
    else:
        return divide(x, y, n, image)  # n*n이 모두 같은 숫자가 아니라면 분할하여 4가지 방향에서 다시 check_same 실행

# 기존 n*n 배열에서 해당되지 않은 경우, 4개의 면으로 분할하여 다시 검사
def divide(x, y, n, image):  
    n2 = n // 2
    top_left = check_same(x, y, n2, image)
    top_right = check_same(x, y + n2, n2, image)
    bottom_left = check_same(x + n2, y, n2, image)
    bottom_right = check_same(x + n2, y + n2, n2, image)
    value = "(" + top_left + top_right + bottom_left + bottom_right + ")"
    return value

N = int(input())
image = []
for _ in range(N):
    image.append(list(input()))

print(check_same(0, 0, N, image))
