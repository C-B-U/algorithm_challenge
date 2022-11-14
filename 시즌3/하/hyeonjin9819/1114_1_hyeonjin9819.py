one = []
sec = []

for i in range(3):
    data = list(map(int, input().split()))
    if i == 1:
        one.append(data[1])
        sec.append(data[0])
    else:
        one.append(data[0])
        sec.append(data[1])

value = min(one) - min(sec)

if abs(value) >= 2:
    print(min(min(one), min(sec))*2 +1)
else:
    print(min(one) + min(sec))
