broken_finger = int(input())
max_uses_of_bf = int(input())

ans = 0
if broken_finger == 1 or broken_finger == 5:
    ans = (max_uses_of_bf * 8) + (broken_finger - 1)
elif max_uses_of_bf % 2 == 1:
    ans = ((max_uses_of_bf//2) * 8) + (9 - broken_finger)
else:
    ans = ((max_uses_of_bf//2) * 8) + (broken_finger - 1)

print(ans)
