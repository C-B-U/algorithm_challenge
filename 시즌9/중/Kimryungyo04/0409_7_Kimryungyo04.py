def eratosthenes_sieve(n):
    prime_list = [True] * (n+1)
    prime_list[0] = prime_list[1] = False

    for i in range(2, int(n**0.5)+1):
        if prime_list[i]:
            for j in range(i*i, n+1, i):
                prime_list[j] = False
    primes = [i for i in range(2, n+1) if prime_list[i]]
    return primes

def main():
    test_count = int(input())

    for i in range(test_count):
        integer = int(input())
        primes = eratosthenes_sieve(integer)

        multiplied = {}
        for prime in primes:
            while (integer % prime == 0):
                integer /= prime

                if prime not in multiplied: multiplied[prime] = 0
                multiplied[prime] += 1

        if integer != 1: multiplied[integer] = 1

        for multiply, count in multiplied.items():
            print(multiply, count)

main()