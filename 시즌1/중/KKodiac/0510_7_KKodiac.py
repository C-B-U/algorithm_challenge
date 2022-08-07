def solution():
    N = int(input()) # 2 <= N <= 11
    A = list(map(int, input().split())) # 1 <= Ai <= 100
    operators = list(map(int, input().split()))
    itercount = 0
    def solve(itercount, result, add, sub, mul, div):
        global max_val
        global min_val
        if itercount == N:
            max_val = max(max_val, result)
            min_val = min(min_val, result)
        if add > 0:
            solve(itercount+1, result+A[itercount], add-1, sub, mul, div)
        if sub > 0:
            solve(itercount+1, result-A[itercount], add, sub-1, mul, div)
        if mul > 0:
            solve(itercount+1, result*A[itercount], add, sub, mul-1, div)
        if div > 0:
            if result < 0:
                solve(itercount+1, -(-result//A[itercount]), add, sub, mul, div-1)
            else:
                solve(itercount+1, result//A[itercount], add, sub, mul, div-1)
            
    solve(itercount+1, A[0], operators[0], operators[1], operators[2], operators[3])

    print(max_val)
    print(min_val)

if '__main__' == __name__:
    max_val = -1000000000
    min_val = 1000000000 
    solution()