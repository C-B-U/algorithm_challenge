def solution():
    N = int(input())

    A = 1
    for i in list(map(int, input().split())):
        A *= i

    M = int(input())
    B = 1
    for j in list(map(int, input().split())):
        B *= j

    def gcd(a, b):
        while b > 0 :
            tmp = a%b
            a = b
            b = tmp
        return a

    result = gcd(A, B)
    if len(str(result)) > 9:
        print(str(result)[len(str(result))-9:])
    else:
        print(result)


if '__main__' == __name__:
    solution()
