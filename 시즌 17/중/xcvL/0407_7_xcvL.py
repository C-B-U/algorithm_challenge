import sys

input = sys.stdin.readline

S = input().rstrip()
T = input().rstrip()

n01 = 1
while S != T:
    try:
        if T[-1] == "A":
            T = T[:-1]
        elif T[-1] == "B":
            T = T[:-1]
            T = T[::-1]
        else:
            n01 = 0
            break
    except:
        n01 = 0
        break
print(n01)