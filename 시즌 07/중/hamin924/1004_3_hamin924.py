h,w = map(int, input().split())
m = [list(input()) for _ in range(h)]
result = 0
for i in range(h):
    line = 0
    for j in m[i]:
        if j == '/' or j == '\\': line += 1
				#line이 홀수개일때 .이 도형안에, 짝수개일때 도형밖에(도형이 닫힌거니까) 있다고 생각
        if line % 2 == 1 and j == '.': result += 1
    result += (line // 2)
print(result)