#2641

size = int(input())
sample = list(map(int,input().split()))
reverse = []

for i in sample:
    i = i + 2
    if i>4:
        i = i - 4
    reverse.insert(0,i)


count = int(input())

arr = []

for i in range(0,count):
    arr.append(list(map(int,input().split())))

result = []

for shape in arr:
    for i in range(0, size):
        buffer = shape[i:] + shape[:i]
        if buffer == sample or buffer == reverse:
            result.append(shape)
            break

print(len(result))

for s in result:
    print(' '.join(list(map(str, s))))