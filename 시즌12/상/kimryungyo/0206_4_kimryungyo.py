# [ 풀이 ]
# 1. 단어를 하나씩 붙여보면서 가능한 경우를 기록하고 가능한 최대 길이를 출력하면 된다.
#
# 2. 그러나 실제로 단어를 연결하면서 계산하면 시간 초과 및 메모리 초과가 발생할 것이다.
#    따라서 단어를 연결할 때는 현재 사용한 단어 목록과 마지막 문자만 기록해야한다.
#    (가장 긴 문자열의 '길이'를 구하기 위해선 이외의 정보는 필요하지 않다는 걸 금방 이해할 수 있을 것이다.)
#
# 3. 하지만 사용한 단어 목록을 저장할 때도 직접 문자열을 저장하면 메모리 초과가 발생한다.
#    따라서 현재 사용한 단어 목록은 비트마스킹을 이용해 저장해야한다.
# 
#    - 비트마스킹 : 5개의 단어가 있을 때 3번 단어만 사용했다면 11011의 이진수로 저장하는 방법
#                  오른쪽부터 i번째 비트는 i번 단어를 사용했는지 아닌지를 나타낸다. (사용하지 않은 경우 1, 사용한 경우 0)
#
#                  문자열은 최대 16개, 최대 100자리이므로 비트마스킹이 아닌 문자열을 직접 저장하면 최악의 경우 하나의 목록에 1600바이트를 사용한다. (1 char = 1 byte)
#                  그러나 비트마스킹을 이용하면 1비트당 한 단어씩, 최악의 경우에도 하나의 목록을 2바이트로(16bit) 저장할 수 있다. (800분의 1 메모리 사용)
#
#    + 비트마스크 결과를 해시맵을 사용해 저장할 수도 있겠지만 파이썬의 경우 해시 연산이 상당히 무겁기 때문에 리스트를 이용했다.
#      단어의 수는 최대 16개로, 경우의 수가 65536이므로 65536 길이의 리스트를 활용하면 된다.
#
# 0. 문제 풀다 알았는데 문제에 N = 1인 경우의 데이터가 없는 거 같다..
#

# 각 문자의 번호를 반환하는 함수
def convert_to_index(char):
    if char == "A": return 0
    if char == "E": return 1
    if char == "I": return 2
    if char == "O": return 3
    if char == "U": return 4

# 단어 정보 입력, 각 단어의 정보는 시작 문자, 마지막 문자, 길이, 단어 번호만 저장한다.
N = int(input())
WORDS = []
for idx in range(N):
    word = input()
    w_start = convert_to_index(word[0])
    w_end = convert_to_index(word[-1])
    info = (w_start, w_end, len(word), idx)
    WORDS.append(info)

# 만든 단어들을 기록하는 리스트 
# dp[사용한 단어 정보][만든 문자열의 마지막 문자 번호] 는 해당 정보들로 문자열을 만들었는지를 나타낸다.
# 값이 False 경우는 그 문자열을 못 만들었다는 의미
created = [ [ False ] * 5 for _ in range(65536) ]

# 큐에 하나의 단어만 사용하는 초기값들을 추가
queue = []
initial = int('1' * N, 2)
for start, end, leng, idx in WORDS:
    used = initial & ~(1 << idx)
    queue.append( (used, leng, end) )
    created[used][end] = True

# 기존 문자에 단어를 이어붙여 새 문자열을 만들 수 있을 때 까지 문자열을 만든다
max_len = 0
while queue:
    used, leng, end = queue.pop()
    if leng > max_len:
        max_len = leng

    for i in range(N):
        if used & (1 << i):
            w_start, w_end, w_len, w_idx = WORDS[i]

            new_used = used & ~(1 << w_idx)
            new_len = leng + w_len

            if w_start == end and not created[new_used][w_end]:
                created[new_used][w_end] = True
                queue.append( (new_used, new_len, w_end) )

# 만든 문자열 중 최대 길이 출력
print(max_len)
