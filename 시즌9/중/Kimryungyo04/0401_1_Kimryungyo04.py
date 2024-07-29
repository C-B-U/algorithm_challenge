# [ 알고리즘 ]

# 총 N-2 번 반복하므로 결과적으로 첫 폭죽 더미와 마지막 폭죽 더미만 남는다.
# 즉, 첫 폭죽 더미와 마지막 폭죽 더미의 값만 최소화하면 된다.
# 매 반복마다 두 폭죽 더미 중 높이가 더 높은 폭죽 더미의 옆에 있는 폭죽 더미를 터트리면 된다.

# ->

# 1. 양 끝 폭죽 더미의 높이가 다른 경우 같아질 때까지 높이가 높은 쪽 옆에 있는 폭죽을 터트린다.
# 2. 폭죽의 높이가 같아졌으면 양쪽 번갈아 가면서 옆에 있는 폭죽을 터트린다.

# 시간 제한 : 1초, 반복문 사용 X
# 평균 소요 시간 (입력 길이 상관 없이) : 40ms ~ 60ms (컴파일 후 1ms ~ 0ms)
# 시간 복잡도 : O(1)

def main(firework_pile_count: int = None, firework_list: str = None) -> int:
    """씨부엉 난이도 중 1일차 알고리즘 함수

    Args:
        firework_pile_count (int, optional): 폭죽 더미의 개수
        firework_list (str, optional): 폭죽 더미의 목록 (ex: "12 52 36 45")

    Returns:
        int: 남은 폭죽의 높이 중 높은 값의 최솟값
    """

    # 폭죽 더미 수 입력
    if firework_pile_count == None: firework_pile_count = int(input())

    # 폭죽 더미들 입력 및 첫 더미와 마지막 더미 구하기 + 메모리 최적화
    if firework_list == None: firework_list = input()
    firework_pile = [int(firework_list.split(" ", 1)[0]), int(firework_list.rsplit(" ", 1)[1])]
    del firework_list

    # 총 터트릴 수 있는 폭죽 수 구하기
    available_fireworks_count = firework_pile_count - 2

    # 첫 더미와 마지막 더미를 높은 더미와 낮은 더미로 구분하기
    firework_pile.sort()
    high, low = firework_pile[1], firework_pile[0]

    # 두 더미의 높이 차 구하기
    height_difference = high - low

    # 두 더미의 높이차가 총 터칠 수 있는 폭죽 수보다 큰 경우 높은 더미에서 총 터칠 수 있는 폭죽 수만큼 낮춘 값 반환
    if height_difference >= available_fireworks_count:
        return high - available_fireworks_count

    else:
        # 두 폭죽 사이의 높이차 해소하기
        high -= height_difference
        available_fireworks_count -= height_difference
        firework_pile_count -= height_difference

        # 두 폭죽의 높이가 같으니 연산량을 줄이기 위해 하나의 변수로 통합
        firework = high

        # 폭죽이 2개 또는 3개 밖에 안 남을 때 까지 번갈아 가며 폭죽 터트리기
        exploded_firework = available_fireworks_count // 2
        firework -= exploded_firework
        available_fireworks_count -= exploded_firework * 2

        # 남은 터칠 수 있는 폭죽 수(1 또는 0)에 따라 알맞은 값 반환
        if available_fireworks_count == 1: return firework - 1
        else: return firework


def shortened_main_function():
    """주석을 제거한 main() 함수, 역할은 같음"""
    firework_pile_count = int(input())
    firework_list = input()
    firework_pile = [int(firework_list.split(" ", 1)[0]), int(firework_list.rsplit(" ", 1)[1])]
    del firework_list
    available_fireworks_count = firework_pile_count - 2
    firework_pile.sort()
    high, low = firework_pile[1], firework_pile[0]
    height_difference = high - low
    if height_difference >= available_fireworks_count: return high - available_fireworks_count
    else:
        high -= height_difference
        available_fireworks_count -= height_difference
        firework_pile_count -= height_difference
        exploded_firework = available_fireworks_count // 2
        high -= exploded_firework
        available_fireworks_count -= exploded_firework * 2
        if available_fireworks_count == 1: return high - 1
        else: return high


def loop_algorithm():
    """반복문을 활용한 알고리즘, 입력 데이터의 길이가 길어질 수록 오래 걸림, 데이터가 길어질 경우 비효율적"""
    count, firework_list = int(input()), input()
    firework_pile = [int(firework_list.split(" ", 1)[0]) - 1, int(firework_list.rsplit(" ", 1)[1]) - 1]
    del firework_list
    for i in range(count-3):
        if firework_pile[0] > firework_pile[1]: firework_pile[0] -= 1
        else: firework_pile[1] -= 1
    return max(firework_pile)


print(shortened_main_function())
