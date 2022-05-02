import sys

def solution():
    N = int(sys.stdin.readline())
    # 1 - 7 - 19 - 37 - 61 - ...

    answer, location = 1, 1
    while N > location:
        location += (answer*6)
        answer += 1

    print(answer)
if __name__ == "__main__":
    solution()
