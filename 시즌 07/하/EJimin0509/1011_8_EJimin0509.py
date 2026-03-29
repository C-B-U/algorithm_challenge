length = int(input())
star = '*'
space = ' '

for i in range(2*(length)-1):
    if i < length:
        print(space*(length-i-1)+star*((i+1)*2-1))
    else:
        print(space*(i-length+1)+star*((2*(length)-1)-2*(i-length+1)))