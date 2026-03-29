# 백준 알고리즘 13268번 '셔틀런' 문제
def shuttle_run(n):
    d = 0
    
    while n > 0:
        d = 0
        # 콘을 지나는 횟수
        for i in [1, 2, 3, 4]:
            # 출발 구간
            for _ in range(i):
                n -= 5
                if n <= 0:
                    d += 5 + n
                    break
                d += 5
            if n <= 0:
                break

            # 복귀 구간
            for _ in range(i):
                n -= 5
                if n <= 0:
                    d -= 5 + n
                    break
                d -= 5
            if n <= 0:
                break

    return d // 5 if d % 5 == 0 else d // 5 + 1

# 입력 받기
n = int(input())
print(shuttle_run(n))