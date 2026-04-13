n = int(input())
for i in range(n):
    a = list(map(int,input("").split()))
    cn = a[0]
    pn = a[1]
    for j in range(pn):
        b = list(map(int,input("").split()))
    print(cn-1)






























"""
n = int(input())
for i in range(n):
    stack_list = []
    
    a = list(map(int,input("").split()))

    cn = a[0]
    pn = a[1]
    save1 = [[]*pn]

    for j in range(pn):
        aaa = []
        aaa = list(map(int,input("").split()))
        if save1[aaa[0]].index(aaa[1]) == False:
            save1[aaa[0]].append(aaa[1])
        aaa.reverse
        if save1[aaa[0]].index(aaa[1]) == False:
            save1[aaa[0]].append(aaa[1])
    
    for j in range(len(save1)):
        stack_list.append(save1[1][j])
        stack_list.index()"""