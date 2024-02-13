n = int(input())

if n == 1:
    print(1)
else:
    length = 1
    spiral = 1
    while n > length:
        length += 6*spiral
        spiral += 1
    print(spiral)