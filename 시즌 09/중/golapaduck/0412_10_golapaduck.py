#2116
import sys
input= sys.stdin.readline

N = int(input())
dice_list = list(list(map(int,input().split())) for _ in range(N))
result = 0

def find(dice,next):
    if dice[0] == next:
        return (max(dice[1], dice[2], dice[3], dice[4]),dice[5])
    elif dice[5] == next:
        return (max(dice[1], dice[2], dice[3], dice[4]),dice[0])
    elif dice[1] == next:
        return (max(dice[4], dice[2], dice[0], dice[5]),dice[3])
    elif dice[3] == next:
        return (max(dice[4], dice[2], dice[0], dice[5]),dice[1])
    elif dice[2] == next:
        return (max(dice[0], dice[5], dice[1], dice[3]),dice[4])
    elif dice[4] == next:
        return (max(dice[0], dice[5], dice[1], dice[3]),dice[2])

for i in range(6):
    sum = 0
    num = 0
    next = dice_list[0][i]
    for _ in range(N):
        buffer, next = find(dice_list[num],next)
        num += 1
        sum += buffer
    if sum > result:
        result = sum

print(result)