def arithmeticSequence(N):
    n=0
    for i in range(1,N+1):
        if ((i<100)or((i%100)//10)*2 == (i//100 + i%10)):
            n += 1
    return n

N = int(input())
print(arithmeticSequence(N))
