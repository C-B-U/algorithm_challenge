n = int(input())
sub = []

for i in range(n):
    a, b = map(int, input().split())
    sub.append(a-b)

sub.sort()

if n%2 == 1:
    print(1)
else:
    print(abs(sub[n//2] - sub[n//2-1]) + 1)