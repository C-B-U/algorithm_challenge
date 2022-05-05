from matplotlib.pyplot import table


def solution():
    """ 수열의 i번째까지의 연속된 값들의 합과 수열의 i번째 인덱스에서 나온 값 중 큰 놈을 고르면 됨 """
    n = int(input())
    sequences = list(map(int, input().split()))
    table = [sequences[0]]

    for i in range(n-1):
        table.append(max(table[i]+sequences[i+1], sequences[i+1]))

    print(max(table))


if '__main__' == __name__:
    solution()