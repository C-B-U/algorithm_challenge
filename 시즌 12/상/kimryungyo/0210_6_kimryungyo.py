# [ 자리합 ] - 1081번 합, 1019번 책 페이지 문제와 유사한 문제
#
# 숫자들을 자세히 보다 보면 어떤 규칙을 찾을 수 있다
# 반년 전에 풀었던 문제라 수학적인 증명은 기억나지 않는다..

def unit_and_count(depth):
    counts = {}
    counts[0] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    counts[1] = [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]

    count = counts[1]
    for depth in range(0, depth):

        add_one = 10 ** depth - 1
        add_default = (depth * 10 ** (depth - 1)) if depth != 0 else 0

        for num in range(1, 10): 
            distance = [add_default] * 10
            distance[num] += add_one

            if 1 <= num + 1 <= 9: 
                distance[num + 1] += 1
            else: 
                distance[0] += 1

            if num == 9: 
                distance[1] += 1

            count = [count[n] + distance[n] for n in range(10)]
            counts[(num + 1) * 10 ** depth] = count.copy()
    
    return counts

def get_number_count(n):
    numbers = list(map(int, str(n)))
    length = len(numbers)
    count_dp = unit_and_count(length)
    count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    for idx in range(length):
        position, number = length - idx, numbers[idx]

        influential = (10 ** (position - 1)) * number
        
        count = [count[n] + count_dp[influential][n] for n in range(10)]
        
        if (position < length) and (number != 0) and (position > 1):
            for add in range(1, position): 
                count[0] += int("9" * add)

        for front in numbers[:idx]: 
            count[front] += number * (10 ** (position - 1))

    return count

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    if a == 0: a = 1

    a_c = get_number_count(a-1)
    b_c = get_number_count(b)

    sum = 0
    for i in range(10):
        sum += (b_c[i] - a_c[i]) * i

    print(sum)