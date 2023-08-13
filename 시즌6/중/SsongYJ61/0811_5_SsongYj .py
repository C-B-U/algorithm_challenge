n = int(input())
lst = [list(map(int,input()))for _ in range(n)]

def quard_tree(x,y,n) :
    flag = lst[x][y]
    for i in range(x, x+n) :
        for j in range(y, y+n) :
            if flag != lst[i][j] :
                flag = -1
                break
    if flag == -1 :
        print("(", end = "")
        n = n // 2
        quard_tree(x,y,n)
        quard_tree(x,y+n,n)
        quard_tree(x+n,y,n)
        quard_tree(x+n,y+n,n)
        print(")",end = "")

    elif flag == 1:
        print(1,end = "")
    else :
        print(0, end = "")

quard_tree(0,0,n)



