import heapq
import sys
input = sys.stdin.readline
def solution():
    n = int(input())
    table = list()
    for _ in range(n):
        nums = list(map(int, input().split()))
        if not table:
            for num in nums:
                heapq.heappush(table, num)
        else:
            for num in nums:
                if table[0] < num:
                    heapq.heappush(table, num)
                    heapq.heappop(table)

    print(table[0])


if '__main__' == __name__:
    solution()
