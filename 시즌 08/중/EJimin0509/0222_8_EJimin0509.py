import sys
input = sys.stdin.readline

N = int(input())
cranes = list(map(int, input().split()))
M = int(input())
boxes = list(map(int, input().split()))

cranes.sort(reverse=True)
boxes.sort(reverse=True)

cnt = 0

if boxes[0] > cranes[0]: cnt = -1
else:
    while boxes:
        for c in cranes:
            if boxes and c < boxes[-1]:
                continue
            for b in boxes:
                if c >= b:
                    boxes.remove(b)
                    break
        cnt+=1
        
print(cnt)