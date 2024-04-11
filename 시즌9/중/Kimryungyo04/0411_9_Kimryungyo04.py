# [ 알고리즘 ]
# 답들을 정렬해보면 다음과 같은 규칙이 존재한다.
# 해당 규칙을 통해 값을 구한다.
#
# 자리를 바꾼 횟수    : 0 0 1 2 4 6 9 12 16 20 25 30
# 각 횟수 사이의 차이 : 0 0 1 1 2 2 3  3  4  4  5  5

def main():
    n = int(input())
    result = 0
    for i in range(n): result += i // 2
    print(result)

main()