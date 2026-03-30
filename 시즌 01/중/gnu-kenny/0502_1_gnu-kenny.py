import sys
input = sys.stdin.readline


def main():
    goal = int(input()) - 1

    i = 0
    while True:
        if goal <= i*6:
            print(i+1)
            break

        goal -= i*6
        i += 1


if __name__ == "__main__":
    main()
