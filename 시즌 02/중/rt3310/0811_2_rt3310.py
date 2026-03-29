n = int(input())

result = 0
table = []
for i in range(n):
    table.extend(list(map(int, input().split())))
    table.sort(reverse=True)
    while len(table) > n:
        table.pop()
        
print(table[-1])