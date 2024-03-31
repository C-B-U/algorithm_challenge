# [ 알고리즘 ]

# N-2번 반복하므로 결과적으로 첫 폭죽 더미와 마지막 폭죽 더미만 남는다.
# 즉, 첫 폭죽 더미와 마지막 폭죽 더미의 값만 최소화하면 된다.
# 매 반복마다 두 폭죽 더미 중 높이가 더 높은 폭죽 더미의 옆에 있는 폭죽 더미를 터트리면 된다.

# ->

# 1. 양 끝 폭죽 더미의 높이가 다른 경우 같아질 때 까지 높이가 높은쪽 옆에 있는 폭죽을 터트린다
# 2. 폭죽의 높이가 같아졌으면 양쪽 번갈아가면서 옆에 있는 폭죽을 터트린다

def main():
    # 폭죽 더미 수 입력
    firework_pile_count = int(input())

    # 폭죽 더미들 입력 및 첫 더미와 마지막 더미 구하기
    firework_list = input()
    firework_pile = int(firework_list.split(" ", 1)[0]), int(firework_list.rsplit(" ", 1)[1])

    # 총 터트릴 수 있는 폭죽 수 구하기
    available_fireworks_count = firework_pile_count - 2

    # 첫 더미와 마지막 더미를 높은 더미와 낮은 더미로 구분하기
    if firework_pile[0] >= firework_pile[1]: high, low = firework_pile[0], firework_pile[1]
    else: high, low = firework_pile[1], firework_pile[0]

    # 두 더미의 높이 차 구하기
    height_difference = abs(high - low)

    # 두 더미의 높이차가 총 터칠 수 있는 폭죽 수보다 큰 경우 높은 더미에서 총 터칠 수 있는 폭죽 수 만큼 낮춘 값을 출력하기
    if height_difference >= available_fireworks_count:
        return high - available_fireworks_count
    
    else:
        # 두 폭죽 사이의 높이차 해소하기
        high -= height_difference
        available_fireworks_count -= height_difference
        firework_pile_count -= height_difference

        # 폭죽이 2개밖에 안 남을때 까지 번갈아가며 폭죽 터트리기
        planned_fireworks = available_fireworks_count // 2

        high -= planned_fireworks
        low -= planned_fireworks
        available_fireworks_count -= planned_fireworks * 2
        firework_pile_count -= planned_fireworks * 2

        if firework_pile_count == 4: return high - 2
        if firework_pile_count == 3: return high - 1
        elif firework_pile_count == 2: return high

print(main())
