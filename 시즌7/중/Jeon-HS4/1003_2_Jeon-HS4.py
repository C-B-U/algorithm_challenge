m,n = map(int, input().split())

maximum = 1000000  # 문제에서 제시된 최대값
primeCheck = [True for i in range(maximum+1)]
primeCheck[1] = False  # 1은 소수가 아니므로 미리 제외

for i in range(2, maximum+1):  # 2부터 최대값까지의 소수를 미리 탐색
    if(primeCheck[i] == True):  # 해당 숫자가 소수일 경우
        for j in range(i*2, maximum+1, i):  # 해당 숫자의 배수들을 소수 목록에서 제외
            primeCheck[j] = False

for p in range(m, n+1):  # m부터 n 까지 숫자 중에서 소수 List에 존재하는지 탐색 후 출력
    if(primeCheck[p] == True):
        print(p)
