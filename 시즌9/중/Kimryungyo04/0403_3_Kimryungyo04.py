# [ 알고리즘 ]
# 1 -> 2 -> 3 -> 4 의 순서로 그린 도형이 있다고 할 때 해당 도형과 같은 도형이 그려지는 경우는 다음과 같다.
#
# 1. 배열은 같으나 시작 지점이 같거나 다른 경우 (ex: 3 -> 4 -> 1 -> 2)
# 2. 모든 방향이 반대이고 순서도 반대인 동시에 시작 지점이 같거나 다른 경우  (3 -> 4 -> 1 -> 2)
#
# 따라서 그리는 순서를 입력받으면 다음과 같은 과정을 통해 여러 경우들을 만든 후 표준 모양과 비교한다.

# [ 예시 ]
# 1. (1 -> 2 -> 3 -> 4)란 입력을 받았다.

# 2. 해당 입력에서 시작 지점을 바꾼 순서들을 찾는다.
#     ㄴ (2 -> 3 -> 4 -> 1), (3 -> 4 -> 1 -> 2), (4 -> 1 -> 2 - > 3)

# 3. 입력 받은 모양의 방향을 반전 시킨다.
#     ㄴ (2 -> 1 -> 4 -> 3)

# 4. 반전시킨 순서의 시작 지점을 바꾼 순서들을 찾는다.
#     ㄴ (2 -> 1 -> 4 -> 3), (1 -> 4 -> 3 -> 2), (4 -> 3 -> 2 - > 1)

# 구한 순서들 중에 표준 모양과 일치하는 순서가 있다면 해당 모양은 표준 모양과 일치한다.

def reverse_shape(shape: list):
    """모양을 그리는 순서를 반전시키는 함수"""
    shape.reverse()
    new_shape = list()
    for draw in shape:
        if draw == 1: new_shape.append(3)
        elif draw == 3: new_shape.append(1)
        elif draw == 2: new_shape.append(4)
        else: new_shape.append(2)
    return new_shape

def rotate_shape(shape: list):
    """모양을 그리는 순서를 회전시키며 시작 위치가 다른 순서들을 반환하는 함수"""
    length = len(shape)
    for i in range(length):
        yield shape[i:] + shape[:i]

def main():
    """씨부엉 난이도 중 3일차 알고리즘 함수"""
    # 표준 도형 정보 입력
    shape_len = int(input())
    standard_shape = list(map(int, input().split()))

    # 비교 도형 정보 입력
    comparison_shape_count = int(input())

    # 모든 비교 도형 체크
    matched_shapes = []
    for i in range(comparison_shape_count):
        # 비교 도형 입력
        shape_input = input()
        comparison_shape = list(map(int, shape_input.split()))

        # 비교할 도형 목록 (입력 받은 도형과 반전 시킨 도형)
        comparison_shapes = [comparison_shape, reverse_shape(comparison_shape.copy())]

        matched = False
        # 도형 체크 과정
        for comparison_shape in comparison_shapes:
            # 시작 지점을 돌려가며 체크
            for rotated_shape in rotate_shape(comparison_shape):
                # 일치하는 경우 루프 종료
                if standard_shape == rotated_shape:
                    matched = True
                    break
            if matched == True: break

        # 일치하는 경우가 감지된 경우 일치하는 도형 목록에 해당 도형 추가
        if matched == True: matched_shapes.append(shape_input)
        
    # 결과 출력
    print(len(matched_shapes))
    for shape in matched_shapes: print(shape)

main()