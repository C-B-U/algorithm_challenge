import sys
from typing import List

def solution():
    def convertToB(base10: int) -> List[int]:
        baseB = list()
        while base10 > 0:
            baseB.append(base10%B)
            base10 //= B

        return baseB[::-1]


    A, B = map(int, sys.stdin.readline().split())
    m = int(sys.stdin.readline())
    baseA = list(map(int, sys.stdin.readline().split()))[::-1]

    base10 = sum([num*(A**digit) for digit, num in enumerate(baseA)])

    baseB = convertToB(base10)

    print(" ".join(str(b) for b in baseB))


if '__main__' == __name__:
    solution()
