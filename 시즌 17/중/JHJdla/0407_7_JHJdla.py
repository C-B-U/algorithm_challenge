import sys

a = input().strip()
b = input().strip()

la = len(a)
lb = len(b)

while lb > la:
    if b[lb-1] == "A":
        b = b[:lb-1]
    else:
        b = b[:lb-1]
        b = b[::-1]
    lb = len(b)

if a == b:
    print(1)
else:
    print(0)
