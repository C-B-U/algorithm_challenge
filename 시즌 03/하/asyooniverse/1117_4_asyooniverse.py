n = int(input())
l = list(map(int, input().split()))

result = [1]
for i in range(1, n):
    result = result[:i-l[i]] + [i+1] + result[i-l[i]:] 
    
for i in result:
    print(i, end = ' ')