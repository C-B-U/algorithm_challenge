straw = int(input())
length = []

for i in range(straw) :
    length.append(int(input()))

length.sort(reverse = True)

result = 0
for i in range(len(length)-2) :
    if length[i] < length[i+1] + length[i+2] :
        result = length[i] + length[i+1] + length[i+2]
        break
    else :
        result = -1

print(result)
