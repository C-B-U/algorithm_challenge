hurt = int(input())
cnt = int(input())

if hurt == 1 :
    print(cnt * 8)

elif hurt == 5 :
    print((cnt * 8) + (hurt - 1))

else :
    if cnt % 2 == 0 :
        cnt //= 2
        print((cnt * 8) + (hurt - 1))
    else :
        print((cnt * 8) + (1 - hurt))
