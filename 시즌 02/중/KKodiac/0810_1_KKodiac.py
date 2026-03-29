# BOJ 18870 좌표압축
import sys
input = sys.stdin.readline
def solution():
    n = int(input())
    coords = list(map(int, input().split()))
    sorted_coords = sorted(set(coords))
    dict_coords = {i[1]: i[0] for i in enumerate(sorted_coords)}
    print(" ".join(str(dict_coords[i]) for i in coords))

if '__main__' == __name__:
    solution()
