import sys

a = list(map(int , input().split()))
al = a[0]
even = a[0] // 2
odd = (a[0] + 1) // 2
save = (a[0] - 1) // 3 + 1
cun = 1

if a[1] == 0:
    print(1)
    exit(0)
    
if a[0] == 1:
    print(2)
    exit(0)

if al <= a[1]:
    cun += 1
if odd <= a[1]:
    cun += 1
if even <= a[1]:
    cun += 1
if save <= a[1] and al >= 3:
    cun += 1
if save + even <= a[1] and al >= 3:
    cun += 1
if save + odd <= a[1] and al >= 3:
    cun += 1
if save + al <= a[1] and al >= 3:
    cun += 1

print(cun)