n = int(input());
arr = [];
for i in range(n):    
    arr.append(map(int,input().split()));

earns = [0] * (n+1);
for i in range(n):
    t, p = arr[i];
    earns[i] = max(earns[i],earns[i-1]);
    if i+t <= n:
        earns[i+t] = max(earns[i+t],earns[i]+p);
print(max(earns));