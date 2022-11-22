# 맨 처음에는 딸기우유를 한 팩 마신다.
# 딸기우유를 한 팩 마신 후에는 초코우유를 한 팩 마신다.
# 초코우유를 한 팩 마신 후에는 바나나우유를 한 팩 마신다.
# 바나나우유를 한 팩 마신 후에는 딸기우유를 한 팩 마신다. 

# 0 딸기, 1 초코, 3 바나나

n = int(input())
milk = list(map(int,input().split()))

count = 0

for i in range(n):
    if milk[i] == count % 3:
        count += 1

print(count)