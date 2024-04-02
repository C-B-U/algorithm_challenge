N = int(input())
while N>0:
    Bool = True
    mList = list()
    for i in range(N):
        mList.append(int(input()))
    mList.sort()
    if mList[0]>200:
        Bool = False
    if mList[-1]<1322:
        Bool = False
    for j in range(N-1):
        if (mList[j+1]-mList[j])>200:
            Bool = False
            break;
    if Bool:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")
    N = int(input())