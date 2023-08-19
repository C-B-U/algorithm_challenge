x, y = map(int, input().split())

answer = x + y

while(x != y):
  if(x >= y):
    x -= y
  else:
    y -= x
  
answer -= x

print(answer)
