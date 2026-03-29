import math
DHW = input().split()
y = (math.sqrt((math.pow(int(DHW[0]), 2))/(math.pow(int(DHW[2])/int(DHW[1]), 2) + 1)))
x = (int(DHW[2])/int(DHW[1])*y)
print(math.floor(y),math.floor(x))