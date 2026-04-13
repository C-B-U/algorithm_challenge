import sys


def solve():
    input_data = sys.stdin.read().split()
    n = int(input_data[0])
    s = input_data[1]
    if n % 3 != 0:
        print("mix")
        return

    o_count = s.count('O')
    h_count = n - o_count
    if h_count != o_count * 2:
        print("mix")
        return

    h_cnt = 0
    o_cnt = 0
    for char in s:
        if char == 'H':
            h_cnt += 1
        else:
            o_cnt += 1
            if o_cnt > h_cnt:
                print("mix")
                return

    h_cnt = 0
    o_cnt = 0
    for char in reversed(s):
        if char == 'H':
            h_cnt += 1
        else:
            o_cnt += 1
            if o_cnt > h_cnt:
                print("mix")
                return
    print("pure")


if __name__ == '__main__':
    solve()