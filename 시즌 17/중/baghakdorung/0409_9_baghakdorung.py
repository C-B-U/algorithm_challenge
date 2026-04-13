import sys


def solve():
    n = int(sys.stdin.readline())
    words = [sys.stdin.readline().strip() for _ in range(n)]
    dic = {}

    for word in words:
        for i in range(len(word)):
            char = word[i]
            power = 10 ** (len(word) - 1 - i)

            if char in dic:
                dic[char] += power
            else:
                dic[char] = power

    weights = sorted(dic.values(), reverse=True)
    total_sum = 0
    num = 9
    for weight in weights:
        total_sum += weight * num
        num -= 1

    print(total_sum)


if __name__ == "__main__":
    solve()