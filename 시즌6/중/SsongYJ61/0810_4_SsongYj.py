n = int(input())

option = [] 

for i in range(n):
    inp_list = list(input().rstrip().split())
    
    flag = 0 
    data = []
    for j in range(len(inp_list)):
        if inp_list[j][0].lower() not in option and inp_list[j][0].upper() not in option:
            option.append(inp_list[j][0])
            flag = 1
            inp_list[j] = '[' + inp_list[j][0] + ']' + inp_list[j][1:]
            break

        
    if flag == 0: 
        for j in range(len(inp_list)):
            flag = 0
            for k in range(len(inp_list[j])):
                if inp_list[j][k].lower() not in option and inp_list[j][k].upper() not in option:  
                    option.append(inp_list[j][k])
                    if k != len(inp_list[j])-1:
                        inp_list[j] = inp_list[j][:k] + '[' + inp_list[j][k] + ']' + inp_list[j][k + 1:]
                    else:
                        inp_list[j] = inp_list[j][:k] + '[' + inp_list[j][k] + ']'
                    flag = 1
                    break
            if flag:
                break
    print(' '.join(inp_list))
