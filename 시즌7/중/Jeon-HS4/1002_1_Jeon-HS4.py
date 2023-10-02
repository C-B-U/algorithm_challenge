n,m = map(int, input().split())
chessMap = []
results = []

for _ in range(n):
    chessMap.append(input())

# 8x8 크기의 체스판 설정
for i in range(n-7):
    for j in range(m-7):
        black = 0
        white = 0
        # 처음 시작이 검정색인 경우
        for a in range(i,i+8):
            for b in range(j,j+8):
                if((a+b) % 2 == 0):
                    if(chessMap[a][b] == "W"):
                        black += 1
                else:
                    if(chessMap[a][b] == "B"):
                        black += 1
        # 처음 시작이 흰색인 경우
        for a in range(i,i+8):
            for b in range(j,j+8):
                if((a+b) % 2 == 0):
                    if(chessMap[a][b] == "B"):
                        white += 1
                else:
                    if(chessMap[a][b] == "W"):
                        white += 1
        results.append(black if black <= white else white)

print(min(results))
