import sys
input = sys.stdin.readline

def solve(s):
    # 3의 배수인지
    if len(s) % 3 != 0:
        return "mix"

    k = len(s) // 3 # 만들어야 HOH의 개수

    h_pos = []
    o_pos = []

    # H와 O의 위치 저장
    for i in range(len(s)):
        if s[i] == 'H':
            h_pos.append(i)
        elif s[i] == 'O':
            o_pos.append(i)

    # O가 k개면 H는 2k개 있어야
    if len(h_pos) != 2 * k or len(o_pos) != k:
        return "mix"

    # 1~k개까지 위치 확인
    for i in range(k):
        # 왼쪽 H
        left_h = h_pos[i]

        # O
        o = o_pos[i]

        # 뒤의 H
        right_h = h_pos[i + k]

        # 하나라도 어긋나면 틀림
        if left_h < o and o < right_h:
            pass
        else:
            return "mix"

    # 한 번도 안 걸렸으면
    return "pure"


# 입력 처리 및 실행
length = int(input())
s = input().strip()

print(solve(s))
