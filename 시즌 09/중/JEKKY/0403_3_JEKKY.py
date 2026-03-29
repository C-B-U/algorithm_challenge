from collections import deque
import sys
input = sys.stdin.readline

convert = lambda x : (x + 2) % 4 if x != 2 else 4

N = int(input())
standard = deque(map(int, input().split()))
rev_standard = deque(map(convert, standard))
rev_standard.reverse()

cnt = 0
result = list()

for _ in range(int(input())) :
  ctr_grp = deque(map(int, input().split()))

  tmp = ctr_grp.copy()
  for _ in range(N) :
    if standard == tmp or rev_standard == tmp :
      cnt += 1
      result.append(ctr_grp)
    tmp.rotate(1)

print(cnt)
for _lst in result :
  print(*_lst)