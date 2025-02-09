# [ 풀이 ] - 탑다운 재귀 DP
#
# 1. 수열은 다음과 같은 특성을 만족해야 한다.
#    - 모든 항이 자연수
#    - 항이 이전 항보다 감소하면 안됨
#    - 모든 항의 합이 M
#
# 2. 남은 항의 수가 slots개, 남은 합이 remains개, 이번 항부터의 최솟값이 minimum인 경우,
#    가능한 수열의 경우의 수를 반환하는 함수 get_candidates(slots, remains, minimum)를 정의한다.
#
#    이 함수 결과는 현재 항을 (0 ~ remains-minimum)로 선택한 경우의 수들의 합으로 이루어진다.
#
#    예를 들어, (N, M, K) = (4, 9, 3)인 경우 get_candidates(4, 9, 2)는 다음과 같이 계산된다.
#
#    get_candidates(4, 9, 2) = get_candidates(3, 9-2, 2) # 이번 항에서 2를 선택한 경우의 수
#                            + get_candidates(3, 9-3, 3) # 이번 항에서 3을 선택한 경우의 수
#                            + ... 
#                            + get_candidates(3, 9-9, 9) # 이번 항에서 9를 선택한 경우의 수
#
#    즉, 이 함수를 재귀적으로 호출하여 전체 경우의 수를 구할 수 있다.
#
# 3. 다만 함수를 매번 호출하다 보면 중복된 값을 여러번 연산하는 경우가 많아질 것이다.
#    따라서 메모제이션을 이용해 중복 연산을 방지해야 매우 큰 경우의 수를 효율적으로 구할 수 있다.
#
# 4. 현재 항에서 특정 수를 선택할 때의 경우의 수를 구하는 걸 해결했으니, 이를 이용해 K번째 수열을 찾을 수 있다.
#
#    4-1. 첫 항에 가능한 수들을 넣어보면서 경우의 수를 구한다.
#         예를 들어 사전순에서 32번째 수열을 찾을려고 할 때,
#         첫 항에서 1을 선택하는 경우의 수가 20, 2를 선택하는 경우의 수가 20, 3을 선택하는 경우의 수가 20이라면
#         첫 항이 1인 수열들은 사전순으로 1~20번, 2를 선택하는 수열은 21~40번, 3을 선택하는 수열은 41~60번 내에 존재한다는 걸 알 수 있다.
#         따라서 32번째 수열의 첫번째 항은 2가 된다.
#
#    4-2. 이 과정을 반복해 첫번째 항부터 N번째 항까지 선택해가면 K번째 수열을 찾아낼 수 있다.
#

N, M, K = map(int, input().split())

# 중복 연산을 방지하기 위한 메모제이션 배열
# memo[slots][remains][minimum] = get_candidates(slots, remains, minimum)의 결과
memo = [ [ [ None ] * (M + 1) for _ in range(M + 1) ] for _ in range(N + 1) ]

def get_candidates(slots, remains, minimum):

    # 남은 슬롯이 0개인 경우
    if slots == 0:
        # 남은 슬롯도 없고 남은 합도 없으면 가능한 수열이므로 경우의 수 1 반환
        # 남은 슬롯이 없는데 합이 남아있는 경우 불가능하므로 0 반환
        return 1 if remains == 0 else 0
    
    # 남은 합으로 남은 슬롯들을 모두 채울 수 없는 경우 0 반환
    if remains < slots * minimum:
        return 0
    
    # 이미 계산한 적이 있는 값인 경우 이전에 계산한 값 반환
    if memo[slots][remains][minimum] is not None:
        return memo[slots][remains][minimum]
    
    # 현재 슬롯에 가능한 모든 수를 넣어보면서 경우의 수를 구한다.
    count = 0
    for candidate in range(minimum, remains+1):
        count += get_candidates(slots-1, remains-candidate, candidate)

    # 계산한 결과를 메모제이션에 저장하고 다음에도 같은 입력이 주어지는 경우
    # 새로운 연산 없이 이 값을 그대로 반환한다
    memo[slots][remains][minimum] = count

    return count

# 항을 하나씩 선택하면서 K번째 배열을 구한다
sequence = []
minimum = 1
remains = M
slots = N
remain_order = K

for i in range(N):
    for candidate in range(minimum, remains+1):
        count = get_candidates(slots-1, remains-candidate, candidate)
        if remain_order > count:
            remain_order -= count
        else:
            sequence.append(candidate)
            remains -= candidate
            minimum = candidate
            slots -= 1
            break

# 배열 출력
print(" ".join(map(str, sequence)))