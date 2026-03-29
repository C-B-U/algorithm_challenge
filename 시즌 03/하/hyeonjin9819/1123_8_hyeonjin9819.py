T = int(input())

for i in range(T):
    data = list(map(int, input().split()))
    def GCD(x,y):
        while(y):
            x,y = y, x%y
        return(x)

    def LCM(x,y):
        result = (x*y) // GCD(x,y)
        return result
    print(LCM(data[0], data[1]),GCD(data[0], data[1]))

