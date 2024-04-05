# [ 알고리즘 ]
# 피보나치 나머지 수열도 피보나치 수열과 마찬가지로 마지막 2개의 요소만 알면 다음 요소도 구할 수 있다.
# 그러므로 첫번째 나머지와 두번째 나머지가 연속으로 나타나는 곳이 있으면 해당 지점이 새로운 주기가 시작되는 위치이다.

def calculate_period(m):
    # 피보나치 나머지 수열의 첫 두 요소
    fibonacci = [1, 1]

    # 주기를 찾을 때 까지 자리를 옮겨가며 체크
    for i in range(int(1e10)):

        # 다음 나머지는 첫번째 나머지 + 두번째 나머지를 합한 후 m으로 나눈 나머지와 같음
        remainder = (fibonacci[0] + fibonacci[1]) % m

        # 나머지 수열을 한 칸 뒤로 옮김
        fibonacci = [fibonacci[1], remainder]

        # 마지막 나머지 2개가 처음 나머지 2개와 같아지는 경우 새로운 주기가 시작된 거와 같으므로 루프 종료
        if fibonacci == [1, 1]: break
    
    # 주기 반환
    return i + 1

def main():
    """씨부엉 난이도 중 6일차 알고리즘 함수"""
    
    # 테스트 수 입력
    num_tests = int(input())

    for i in range(num_tests):
        # 테스트 정보 입력
        num, m = map(int, input().split())

        # 결과 출력
        print(num, calculate_period(m))

main()
