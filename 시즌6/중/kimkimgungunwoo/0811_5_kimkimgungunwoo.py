def check_not_equal(pix):
    f = pix[0][0]
    for i in range(len(pix)):
        for j in range(len(pix[i])):
            if pix[i][j] != f:
                return 1
    return 0

def compress_data(pixel, answer, x, y, M):
    if M == 1:
        answer.append(pixel[y][x])
    else:
        if check_not_equal([row[x:x+M] for row in pixel[y:y+M]]) == 1:
            answer.append("(")
            compress_data(pixel, answer, x, y, M // 2)
            compress_data(pixel, answer, x + M // 2, y, M // 2)
            compress_data(pixel, answer, x, y + M // 2, M // 2)
            compress_data(pixel, answer, x + M // 2, y + M // 2, M // 2)
            answer.append(")")
        else:
            answer.append(pixel[y][x])

N = int(input())
M = N
pixel = []
answer = []

for _ in range(N):
    pixel.append(input())

compress_data(pixel, answer, 0, 0, M)
ans = "".join(answer)
print(ans)
