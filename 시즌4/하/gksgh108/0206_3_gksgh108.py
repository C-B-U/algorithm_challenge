n = []
char = ""
varchar = ""

while 1:
    n = input()
    cnt = 0
    
    if n == '#':
        break
    else:
        char = n[0]
        varchar = n[2:]
    
    for i in range(0, len(varchar)):
        if(varchar[i] == char):
            cnt += 1
    
    print('{0} {1}'.format(char, cnt))
