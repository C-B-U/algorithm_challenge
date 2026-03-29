# 백준 알고리즘 9753번 '짝 곱' 문제

import bisect

# 에라토스테네스의 체로 소수 찾기
def sieve(n):
    a = [True] * (n + 1)
    a[0], a[1] = False, False
    for i in range(2, int(n**0.5) + 1):
        if a[i]:
            for j in range(i * i, n + 1, i):
                a[j] = False
    return [i for i, is_prime in enumerate(a) if is_prime]

# 소수의 곱 목록 생성
def generate_prime_multiples(primes, limit):
    multiples = set()
    for i in range(len(primes)):
        for j in range(i + 1, len(primes)):
            product = primes[i] * primes[j]
            if product > limit:
                break
            multiples.add(product)
    return sorted(multiples)

# 메인 로직
def main():
    n = 50000
    limit = 100001
    primes = sieve(n)
    primes_mul = generate_prime_multiples(primes, limit)
    
    T = int(input())
    results = []
    for _ in range(T):
        K = int(input())
        idx = bisect.bisect_left(primes_mul, K)
        results.append(primes_mul[idx])
    
    # 최종 결과 출력
    print("\n".join(map(str, results)))

main()