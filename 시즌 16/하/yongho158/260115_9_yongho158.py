import sys
input = sys.stdin.readline

n = int(input())
cards = set(map(int , input().split()))

m = int(input())
queries = list(map(int , input().split()))

answer = []
for x in queries : 
    if x in cards : 
        answer.append('1')
    else : 
        answer.append('0')

print(*answer)
