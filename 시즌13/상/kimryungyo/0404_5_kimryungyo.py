# Imos Method(Difference Array)를 이용하여 구간 합을 구하면 된다.
# Imos Method의 구간 업데이트는 O(1), 누적합을 구하는 건 O(N)이므로 여러 구간 덧셈을 효율적으로 처리할 수 있다.

from math import ceil, sqrt
from sys import stdin
input = stdin.readline

H = int(input())
Q, R = map(int, input().split())

diff_array = [ 0 ] * (H + 3)

for _ in range(Q):
    a, b = map(int, input().split())
    
    r = int(ceil((sqrt(8 * a + 1) - 1) / 2))
    c = a - (r * (r - 1)) // 2
    
    moves = H - (r - 1)
    add = b / (moves + 1)
    
    left = c
    right = c + moves

    diff_array[left] += add
    diff_array[right + 1] -= add
    
dest = [0.0] * (H + 2)
for i in range(1, H + 2):
    dest[i] = dest[i - 1] + diff_array[i]

prefix = [0.0] * (H + 2)
for i in range(1, H + 2):
    prefix[i] = prefix[i - 1] + dest[i]

results = []
for _ in range(R):
    a, b = map(int, input().split())
    result = prefix[b] - prefix[a - 1]
    results.append(result)

print("\n".join(map(str, results)))