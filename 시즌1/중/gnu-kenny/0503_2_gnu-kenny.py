import sys
input = sys.stdin.readline


def main():

    a, b = map(int, input().split())
    m = int(input())
    num = 0

    word = list(map(int, input().split()))
    word = word[::-1]

    for idx, i in enumerate(word):
        num += i*(a**idx)
    word = []
    while(num != 0):
        r = num % b
        word.append(r)
        num //= b
    for i in reversed(word):
        print(i, end=" ")


if __name__ == "__main__":
    main()
