#2117
N = int(input())

if N ==1: 
    print(0)
elif N % 2 == 0: 
    print((N // 2 - 1) * (N // 2))
else: 
    print((N // 2) ** 2)