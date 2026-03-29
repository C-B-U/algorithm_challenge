n = int(input())
l = list(map(int, input().split()))

print(round((sum(l)/(max(l)*n))*100,6))