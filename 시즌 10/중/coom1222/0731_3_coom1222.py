"""
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때,
1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.


입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
예제 입력 1
110
예제 출력 1
99
예제 입력 2
1
예제 출력 2
1

"""

N = int(input("1,000보다 작거나 같은 자연수 N: "))

if (N > 1000):
    exit()


def hansu(num):
    # 100이하는 모두 한수이므로
    if num < 100:
        return True

    #3자리 수일때
    str_num = str(num)

    #첫 두자리 숫자 차이계산
    d = int(str_num[1]) - int(str_num[0])

    #다음자리와 현재자리 차이 게산, 공차와 같으면 True, 아니면 False
    for i in range(1, len(str_num)-1):
        if int(str_num[i+1]) - int(str_num[i]) != d:
            return False
    return True


def count_hansu(N):
    count = 0
    for i in range(1, N+1):
        if hansu(i) == True:
            count += 1
    return count

print(count_hansu(N))