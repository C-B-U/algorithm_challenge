N, r, c = list(map(int, input().split(' ')))

arraySize = 2 ** N
arrayCount = arraySize * arraySize

def recur(width, arrayCount, row, col):
    if width == 1:
        if row - 1 == r and col - 1 == c:
            print(arrayCount - 1)
        return
    width = width // 2
    if r < row - width and c < col - width:
        recur(width, arrayCount - width * width * 3, row - width, col - width)
    elif r < row - width and c < col:
        recur(width, arrayCount - width * width * 2, row - width, col)
    elif r < row and c < col - width:
        recur(width, arrayCount - width * width, row, col - width)
    else:
        recur(width, arrayCount, row, col)
        

recur(arraySize, arrayCount, arraySize, arraySize)