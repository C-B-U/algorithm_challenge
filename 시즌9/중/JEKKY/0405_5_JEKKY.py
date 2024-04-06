N, K = map(int, input().split())
def climb(i, cnt):
    if i<3:             return cnt+i
    elif i%3==0:        return climb(i/3*2,cnt+1)
    elif (i-1)%3==0:    return climb((i-1)/3*2+1, cnt+1)
    else:               return climb(i-1, cnt+1)
if climb(N,0)<=K:   print("minigimbob")
else:               print("water")
