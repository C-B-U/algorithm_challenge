x,y,w,s=map(int,input().split())
sm=min(x,y)
bg=max(x,y)
answer=0
if 2*w<=s:
    answer+=2*w*sm
else:
    answer+=sm*s
if (bg-sm)%2==0:
    if w<s:
        answer+=(bg-sm)*w
    else:
        answer+=(bg-sm)*s
else:
    if w<s:
        answer+=(bg-sm)*w
    else:
        answer+=w+(bg-sm-1)*s
print(answer) 