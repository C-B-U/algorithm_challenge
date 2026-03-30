a = list(bin(int(i))[2:] for i in input())
count=0
for j in a:
    if(count>0):
        if(len(j)<3):
            print(0,end='')
        if(len(j)<2):
            print(0,end='')
    print(j,end='')
    count += 1