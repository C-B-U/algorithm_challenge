import sys
import bisect   
input = sys.stdin.readline

days, ticket_price, day_bonus = map(int, input().split())
salary = list(map(int, input().split()))

salary_sum = [0]
for i in range(days):
    salary_sum.append(salary_sum[-1] + salary[i])

longest_vacation = -1
for s in range(1, days + 1): # s : 휴가 시작일
    # (휴가가기 전에 번 돈 x 보너스) + (휴가 후 번 돈) >= 티켓값
    # (salary_sum[s-1] * day_bonus) + (salary_sum[days] - salary_sum[e]) >= ticket_price

    # s는 고정된 상태에서 e를 찾는다.
    # (salary_sum[s-1] * day_bonus) + salary_sum[days] - ticket_price >= salary_sum[e]
    
    target_money = (salary_sum[s-1] * day_bonus) + salary_sum[days] - ticket_price
    # salary_sum은 어차피 오름차순 정렬되어 있으므로 이진탐색을 사용한다.
    idx = bisect.bisect_right(salary_sum, target_money)
    e = idx - 1 # idx는 e+1이므로, e = idx - 1
    
    if e < s: # 티켓이 너-무 비싸서 idx가 엄청 앞쪽에 잡히면 e - s + 1이 음수가 나올 수 있다.
        # 실제로 이거 안해주니까 백준 82% 정도에서 틀렸습니다 나옴.
        continue
    longest_vacation = max(longest_vacation, e - s + 1)
print(longest_vacation)
    
    