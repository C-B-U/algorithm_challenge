#4159

while(True):
    count = int(input())

    if(count == 0):
        break

    list = [0,2844]

    for i in range(0,count):
        distance = int(input())
        list.append(distance)
        list.append(2844 - distance)
        
    list.sort()
    
    result = "POSSIBLE"
    for i in range(0,count*2):
        if(list[i+1] - list[i] > 200):
            result = "IMPOSSIBLE"
            break
        
    print(result)