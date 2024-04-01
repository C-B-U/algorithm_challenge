# [ 알고리즘 ]

# 총 N-2 번 반복하므로 결과적으로 첫 폭죽 더미와 마지막 폭죽 더미만 남는다.
# 즉, 첫 폭죽 더미와 마지막 폭죽 더미의 값만 최소화하면 된다.
# 반복마다 두 폭죽 더미 중 높이가 더 높은 폭죽 더미의 옆에 있는 폭죽 더미를 터트리면 된다.

# ->

# 1. 양 끝 폭죽 더미의 높이가 다른 경우 같아질 때까지 높이가 높은 쪽 옆에 있는 폭죽을 터트린다.
# 2. 폭죽의 높이가 같아졌으면 양쪽 번갈아 가면서 옆에 있는 폭죽을 터트린다.

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

    # 폭죽 더미들 입력 및 첫 더미와 마지막 더미 구하기
    if firework_list == None: firework_list = input()
    firework_pile = int(firework_list.split(" ", 1)[0]), int(firework_list.rsplit(" ", 1)[1])

    # 총 터트릴 수 있는 폭죽 수 구하기
    available_fireworks_count = firework_pile_count - 2

    # 첫 더미와 마지막 더미를 높은 더미와 낮은 더미로 구분하기
    high, low = max(firework_pile), min(firework_pile)

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
        planned_fireworks = available_fireworks_count // 2
        firework -= planned_fireworks
        available_fireworks_count -= planned_fireworks * 2

        # 남은 터칠 수 있는 폭죽 수(1 또는 0)에 따라 알맞은 값 반환
        if available_fireworks_count == 1: return firework - 1
        else: return firework

print(main())
