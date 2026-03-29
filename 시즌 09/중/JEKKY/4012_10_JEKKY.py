"""
주사위가 6면 -> 총 6가지의 경우의 수 탐색(인덱싱으로 옆면 중 제일 큰 값 더하기)
    이때 주사위의 개수만큼 탐색
        주사위의 아랫면 인덱스에 따라 나누고 옆면의 가장 큰 값 더하기
        주사위의 윗면을 찾고 그 윗면에 맞는 값 시작 값으로 설정. 
        윗면의 값으로 다음 주사위의 아랫면의 인덱스 찾고 해당 값 다음 루프의 시작 인덱스로 사용
    이렇게 찾은 옆면의 합 저장
최종 합 중 가장 큰 합 저장. 
"""
N = int(input())
dice = [list(map(int, input().split())) for _ in range(N)]
new_len = []  

for i in range(6):
    start = i
    result = 0
    for j in range(len(dice)):
        if start == 0 or start == 5:
            result += max(dice[j][1:5])
            if j != len(dice) - 1 and start == 0:
                start = dice[j + 1].index(dice[j][5])
            elif j != len(dice) - 1 and start == 5:
                start = dice[j + 1].index(dice[j][0])
        
        elif start == 2 or start == 4:
            result += max(dice[j][0:2] + [dice[j][3]] + [dice[j][5]])
            if j != len(dice) - 1 and start == 2:
                start = dice[j + 1].index(dice[j][4])
            elif j != len(dice) - 1 and start == 4:
                start = dice[j + 1].index(dice[j][2])
        
        elif start == 1 or start == 3:
            result += max([dice[j][0]] + [dice[j][2]] + dice[j][4:])
            if j != len(dice) - 1 and start == 1:
                start = dice[j + 1].index(dice[j][3])
            elif j != len(dice) - 1 and start == 3:
                start = dice[j + 1].index(dice[j][1])
    new_len.append(result)

print(max(new_len))
