n = int(input())
crane = list(map(int, input().split()))
m = int(input())
box = list(map(int, input().split()))

crane.sort(reverse=True)
box.sort(reverse=True)

count = 0
if crane[0] < box[0]:
  print('-1')
else:
  while len(box)>0:
    for i in crane:
      for j in box:
        if i >= j:
          box.remove(j)
          break
    count+=1

  print(count)
