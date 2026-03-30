# [ 풀이 ] - 분할 정복을 이용한 행렬 거듭제곱
#
# 1. 0번째 피보나치 수부터 n번째 피보나치 수 중에서 홀수번째 피보나치 수의 합은 다음과 같다.
#    1-1. n이 홀수인 경우 -> n번째 피보나치 수
#    1-2. n이 짝수인 경우 -> n+1번째 피보나치 수
#
# 2. 즉, 이 문제는 n + (n % 2)번째의 피보나치 수를 출력하라는 문제로 단순화할 수 있다. (mod 1,000,000,007)
#
# 3. n번째 피보나치 수를 효율적으로 구하는 방법은 11444번 문제를 풀어보면 알 수 있다.
#    간략히 설명하자면 일반적인 분할 정복 거듭제곱 아이디어를 행렬에 적용시키면 된다.
#

MOD = 1_000_000_007

class Matrix:
    """2x2 행렬을 연산하는 클래스 + 모듈러"""

    def __init__(self, matrix):
        self.matrix = matrix

    def __mul__(self, other: "Matrix"):
        """2x2 행렬의 곱을 반환하는 함수"""
        a, b = self, other
        return Matrix([
            [ (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD, (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD ],
            [ (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD, (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD ]
        ])

    def __pow__(self, n):
        """분할 정복 거듭제곱을 이용해 행렬의 n제곱을 구하는 함수"""
        result = Matrix([[1, 0], [0, 1]])
        base = self
        while n:
            if n & 1:
                result = result * base
            base = base * base
            n //= 2
        return result

    def __getitem__(self, idx):
        return self.matrix[idx]

def fibo(n):
    """행렬의 거듭제곱을 이용해 n번째 피보나치 수를 구하는 함수"""
    if n < 2: return n

    matrix = Matrix([[1, 1], [1, 0]])
    result = matrix ** (n - 1)
    return result[0][0]

N = int(input())
answer = fibo(N)
print(answer)