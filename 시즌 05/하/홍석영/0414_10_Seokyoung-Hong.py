h, y= map(int,input().split())

DP = [h]
funds = [1.05,1.2,1.35]
year_length = [1,3,5]

for i in range(1,y+1):
    maxs = []
    for j in range(3):
        if len(DP) >= year_length[j]:
            t = DP[i-year_length[j]]*funds[j]
            maxs.append(t)
        else:
            break
    DP.append(int(max(maxs)))

print(max(DP))
