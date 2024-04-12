# [ 알고리즘 ]
# 첫번째 주사위의 모든 경우에 대한 사이드 합을 구한다.
# 가장 큰 사이드 합을 출력한다.


from typing import List         # 타입 힌트를 위한 모듈 임포트
numbers = {1, 2, 3, 4, 5, 6}    # 주사위 숫자 목록


class Cube():
    """주사위의 전개도를 입력받으면 바라보는 면들끼리 짝지어 저장하는 데이터 클래스"""

    # 전개도를 입력받은 후 바라보는 면들끼리 세트로 묶어 저장한다
    def __init__(self, shape: str):
        numbers = list(map(int, shape.split()))
        self.faces: List[set] = [{numbers[0], numbers[5]}, {numbers[1], numbers[3]}, {numbers[2], numbers[4]}]

    # 주사위의 숫자를 입력받으면 바라보는 면의 숫자를 반환하는 함수
    def get_other(self, n): return [ face - {n} for face in self.faces if n in face ][0].pop()


def main():
    """씨부엉 난이도 중 10일차 알고리즘 함수"""

    count = int(input())     # 주사위 개수 입력
    cubes: List[Cube] = []   # 주사위 리스트를 만들고 전개도를 입력받는다
    for i in range(count): cubes.append(Cube(input()))

    total = {}                           # 사이드합을 저장할 딕셔너리 생성

    for base in range(1, 7):             # 첫 주사위의 모든 경우를 계산해본다
        total[base], bottom = 0, base    # 기본값 설정

        for cube in cubes:                                # 주사위들을 순서대로 루프
            top = cube.get_other(bottom)                  # 현재 주사위의 윗면의 숫자를 구한다.
            total[base] += max(numbers - {bottom, top})   # 현재 주사위의 윗면과 아랫면을 제외한 숫자들 중 가장 큰 수를 사이드합에 더한다
            bottom = top                                  # 다음 주사위로 넘어간다

    return max(total.values())           # 사이드합 중 가장 큰 값을 반환한다

print(main())