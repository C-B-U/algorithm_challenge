Mask = list(map(int,input().split()))
Tshirt = list(map(int,input().split()))
Pants = list(map(int,input().split()))

array_1=[]
array_2=[]

array_1.extend((Mask[0],Tshirt[1],Pants[0]))
array_2.extend((Mask[1],Tshirt[0],Pants[1]))

array_1.sort()
array_2.sort()

result = []
result.extend((array_1[0],array_2[0]))
result.sort()

if result[1]-result[0] not in [0,1]:
    print(result[0]*2+1)
else: print(result[0]+result[1])