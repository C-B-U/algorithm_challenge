# [ 알고리즘 ]
# 합의 시작 부분을 2부터 시작해 끝까지 돌아가며 합이 1000000 이하가 되는 모든 경우의 수를 계산한다.
# 해당 경우의 수들을 변수에 저장하고 입력이 들어오면 해당 입력에 해당하는 경우의 수를 출력한다.

def main():
    """씨부엉 난이도 중 4일차 알고리즘 함수"""
    
    # 경우의 수 리스트 생성
    mapping = [0] * 1000001

    # 합의 시작 범위를 1씩 늘려가며 총 100만번 계산
    for start in range(0, 1000000):
        # 합의 끝을 1씩 늘려가며 합의 시작 부분부터 끝 까지의 합을 계산, 합이 백만을 넘어가면 이후 부분의 계산은 생략한다.
        for end in range(start, 1000000):
            sum = int(((start + end + 4) / 2) * (end - start + 1))
            if sum > 1000000: break
            mapping[sum] += 1

    # 입력을 받고 해당 입력에 해당하는 경우의 수를 출력한다.
    while True:
        money = int(input())
        if money == 0: break
        print(mapping[money])

main()