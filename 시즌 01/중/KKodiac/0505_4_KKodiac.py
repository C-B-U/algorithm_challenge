def solution():
    """ 수열의 i번째까지의 연속된 값들의 합과 수열의 i번째 인덱스에서 나온 값 중 큰 놈을 고르면 됨 """
    """ DP 방식으로 생각하는 것 """
    n = int(input())
    sequences = list(map(int, input().split()))
    table = [sequences[0]]

    for i in range(n-1):
        table.append(max(table[i]+sequences[i+1], sequences[i+1]))

    print(max(table))

    """ Kadane's Algorithm : 
    현재까지의 합이 양수라면: 앞으로 더 값이 커질 것이므로 해당 값을 Keep.
    만약 음수라면 다음 합한 값은 무조건 여태 합한 값보다 작아지니 합하는 것을 멈추고 다음 Loop.
    """

    for i in range(1, n):
        if sequences[i-1] > 0:
            sequences[i] += sequences[i-1]
    print(max(sequences))

if '__main__' == __name__:
    solution()