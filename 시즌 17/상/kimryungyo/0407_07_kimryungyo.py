# 벽이 소리를 막을 때마다 2배가 되어서 직접 시뮬레이션을 돌려도 시간 초과가 발생하지 않는다.
# 처음 문제를 읽었을 때는 당연히 레이지 세그먼트 트리라고 생각했는데.. 티어를 보지 않았다면 많이 어렵게 풀었을 거 같다.

from sys import stdin
input = stdin.readline

N = int(input())
walls = [0] + list(map(int, input().split()))
Q = int(input())

answers = []

for _ in range(Q):
    query = list(map(int, input().split()))

    if query[0] == 1:
        _, c, x = query

        noise = x
        idx = c
        while idx >= 1 and noise:
            if walls[idx] <= noise:
                noise -= walls[idx]
                walls[idx] *= 2
                idx -= 1
            else:
                walls[idx] += noise
                break

        noise = x
        idx = c + 1
        while idx <= N and noise:
            if walls[idx] <= noise:
                noise -= walls[idx]
                walls[idx] *= 2
                idx += 1
            else:
                walls[idx] += noise
                break
    else:
        print(walls[query[1]])
