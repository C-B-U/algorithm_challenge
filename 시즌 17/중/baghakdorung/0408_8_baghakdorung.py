import sys


def get_input():
    data = sys.stdin.read().split()
    n = int(data[0])
    k = int(data[1])
    x = int(data[2])
    arr = list(map(int, data[3:]))
    return n, k, x, arr


def sums(n, arr):
    plus = [0] * (n + 1)
    for i in range(n):
        plus[i + 1] = plus[i] + arr[i]
    return plus


def check(length, n, k, x, plus):
    for i in range(n - length + 1):
        if (x * plus[i]) - plus[i + length] >= (k - plus[n]):
            return True
    return False


# n = 주어진 일 수
# k = 콘서트 티켓 비용
# x = 일급 보너스
# arr = 일급
def solve():
    n, k, x, arr = get_input()
    plus = sums(n, arr)
    if (plus[n] * x) < k:
        print(-1)
        return

    low, high = 1, n - 1
    length = -1
    while low <= high:
        mid = (low + high) // 2
        if check(mid, n, k, x, plus):
            length = mid
            low = mid + 1
        else:
            high = mid - 1
    print(length)


if __name__ == "__main__":
    solve()