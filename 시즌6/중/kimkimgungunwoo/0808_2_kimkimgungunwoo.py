f=int(input())
s=int(input())
if f!= 1 and f!= 5:
    if s%2==0:
        answer=s*4+f-1
    else:
        answer=(s-1)*4+8-f+1
else:
    answer=s*8+f-1
print(answer)