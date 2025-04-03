
while 1:
    try:
        s , t = map(str, input().split())
        first = list(s)
        for i in t :
            if first and i == first[0]:
                first.pop(0)
        if not first :
            print("Yes")
        else:
            print("No")
    except:
        break
