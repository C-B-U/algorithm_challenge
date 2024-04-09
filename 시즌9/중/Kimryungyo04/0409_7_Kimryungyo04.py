# [ 알고리즘 ]
# 작은 소수부터 순서대로 곱해진 횟수를 구한 후 출력한다.

def eratosthenes_sieve(n):
    """에라토스테네스의 체 - 소수를 찾는 가장 빠른 알고리즘"""

    # 소수 목록 생성 - True는 소수, False는 소수가 아닌 수
    prime_list = [True] * (n+1)

    # 루트 n 이하의 모든 수를 반복, 루트 n 까지만 확인하는 이유는 위키 등을 참고할 것
    for i in range(2, int(n**0.5)+1):

        # 해당 수가 소수인 경우
        if prime_list[i]:

            # 해당 수의 배수들을 소수가 아닌 수로 지정
            for j in range(i*i, n+1, i): prime_list[j] = False

    # 소수 목록 반환
    return [i for i in range(2, n+1) if prime_list[i]]

def main():
    """씨부엉 난이도 중 7일차 알고리즘 함수"""

    # 테스트 수 입력
    test_count = int(input())

    for i in range(test_count):

        # 테스트 정보 입력
        integer = int(input())

        # 제일 작은 소수부터 순서대로 나누기
        for prime in eratosthenes_sieve(integer):

            # 나누어 떨어지지 않을 때 까지 나눈 후 나눈 횟수 기록
            count = 0
            while (integer % prime == 0):
                integer /= prime
                count += 1

            # 곱해진 횟수 출력
            if count != 0: print(prime, count)

main()
