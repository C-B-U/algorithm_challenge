x,y,w,s=map(int, input().split())
l=min(x,y)
times=[]
times.append(l*s+(x+y-2*l)*w)
times.append((x+y)*w)
if (((x+y)%2)==0):
    times.append(max(x,y)*s)
else : times.append((max(x,y)-1)*s+w)
print(min(times)) 
'''
if (l==0):
    times.append((x+y)*min(w,s))
else:
    for a in range(0,l+1):
        l=a
        sum=x+y-2*l
        if (sum<0): break
        times.append(sum*w+l*s)
'''
   
