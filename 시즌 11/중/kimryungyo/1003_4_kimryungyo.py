# 놓칠만한 부분이 은근 많다..
# 풀이 : 각이 짝수개인 경우에만 모든 선분을 자를 수 있다.

A, B = map(int, input().split())
if B < 4: result = 0
else:
    if A < 4: A = 4
    if A % 2 == 1: A += 1
    if B % 2 == 1: B -= 1
    result = ((B // 2) - (A // 2) + 1) * ((A // 2) + (B // 2))
print(result)
