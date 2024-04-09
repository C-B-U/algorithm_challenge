# [ 알고리즘 ]
# 5x5로 연산량이 적으니 그냥 모든 경우의 수를 구한다

def main():

    # 모든 경우의 이동 경로를 구한다.
    directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
    paths = []
    for d1 in directions :
        for d2 in directions:
            for d3 in directions:
                for d4 in directions:
                    for d5 in directions:
                        paths.append((d1, d2, d3, d4, d5))


    # 맵 데이터 받아오기
    world = []
    for i in range(5): world.append(input().split())


    # 시작 위치와 이동 경로가 주어지면 해당 경로를 따라가서 얻는 숫자를 반환하는 함수
    # 이동 중 맵 밖으로 나가는 경우 None을 반환
    def get_numbers(x, y, path):
        number = world[x][y]
        for step in path:
            if 0 <= (x := x + step[0]) <= 4 and 0 <= (y := y + step[1]) <= 4:
                number += world[x][y]
            else: return None
        return number


    # 모든 시작 위치에 대해 계산
    numbers = set()
    for x in range(5):
        for y in range(5):
            for path in paths:
                if (result := get_numbers(x, y, path)) != None:
                    numbers.add(result)


    # 결과의 길이 출력
    print(len(numbers))

main()
