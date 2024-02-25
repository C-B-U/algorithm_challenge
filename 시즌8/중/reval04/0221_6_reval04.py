import sys
from collections import Counter


def backTracking(pre, l):
    answer = 0

    if l == len(s):
        return 1

    for k in cnt.keys():
        if k == pre or cnt[k] == 0:
            continue

        cnt[k] -= 1 # 현재 단어의 개수를 감소
        answer += backTracking(k, l + 1) 
        cnt[k] += 1

    return answer

s = list(map(str, sys.stdin.readline().strip()))
cnt = Counter(s)
print(backTracking('', 0))
