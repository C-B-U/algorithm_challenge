sigma=[0 for i in range(0,500002)]
sigma[1]=2
for i in range(2,500001):
    sigma[i]=sigma[i-1]+i+1
cases=[0 for i in range(0,1000002)]
for i in range(1,500001):
    for j in range(i-1,0,-1):
        if (sigma[i]-sigma[j]+j+1)>1000000: break;
        cases[sigma[i]-sigma[j]+j+1]+=1


while(1):
    N = int(input())
    if N==0:
        break
    elif N==1:
        print("0")
    else:
        print(cases[N]+1)