a = 300
b = 60
c = 10
t = int(input())

if t % 10 != 0:
    print(-1)
else:
    print(t // a, (t % a) // b, ((t % a) % b) // c)