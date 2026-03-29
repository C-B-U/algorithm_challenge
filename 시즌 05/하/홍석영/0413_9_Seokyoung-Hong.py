x,y = map(int,input().split())

days = 0
for i in range(1,x):
    if i == 2:
        days += 28
    
    elif i in [1,3,5,7,8,10,12]:
        days += 31
    
    else :
        days += 30
        

days += y

DOW = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

print(DOW[days%7])
