# N=1일 때를 제외하면 주사위는 위치에 따라 1, 2, 3면이 보이는 세가지 경우 밖에 존재하지 않는다.
# 회전이 자유로우므로 항상 각 주사위의 노출면 합이 최소가 되는 걸 선택하면 된다.
# N=1일 땐 전체 합에서 최댓값을 뺀 값이 정답이다.

# 2면이 노출되는 주사위의 수 (dices_2) = 모서리의 주사위 수
# 3면이 노출되는 주사위의 수 (dices_3) = 상단 꼭짓점의 주사위 수
# 1면이 노출되는 주사위의 수 (dices_1) = 위 주사위들을 제외한 면의 주사위 수

N = int(input().strip())
faces = list(map(int, input().split()))

# 엣지 케이스 처리
if N == 1:
    print(sum(faces) - max(faces))
    quit()

A, B, C, D, E, F = faces

# 노출면의 수에 따라 합이 최소가 되는 경우 구하기
# 조합을 코드로 구하는 방법도 있겠지만 더 복잡해질 거 같아 직접 작성..
min_1_face = min(faces)

min_2_faces = min(
    A + B, A + C, A + D, A + E,
    B + C, B + D, B + F,
    C + E, C + F,
    D + E, D + F,
    E + F
)

min_3_faces = min(
    A + B + C, A + B + D, A + E + C, A + E + D,
    F + B + C, F + B + D, F + E + C, F + E + D
)

dices_3 = 4
dices_2 = 8 * N - 12
dices_1 = 5 * (N ** 2) - 16 * N + 12
result = dices_3 * min_3_faces + dices_2 * min_2_faces + dices_1 * min_1_face

print(result)