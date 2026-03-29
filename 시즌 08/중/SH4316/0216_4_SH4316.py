n = int(input())

if n % 2 == 1:
    print(1)
    exit()

diff = []

for i in range(n):
    s = input().split(" ")
    diff.append(int(s[0]) - int(s[1]))

diff.sort()
print(diff[n//2] - diff[n//2-1] + 1)
