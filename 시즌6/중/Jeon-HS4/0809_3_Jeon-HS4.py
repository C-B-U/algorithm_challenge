n = int(input())
numbers = []

# 주어진 빨대의 길이를 모두 배열에 저장
for i in range(n):
    numbers.append(int(input()))

# 크기 순서대로 정렬
numbers.sort()
k = len(numbers)-1
answer = -1

while(k>1):  # k, k-1, k-2 3가지 수를 통해 삼각형을 만들것이기 때문에 k<=1의 경우 빨대의 개수가 부족해짐.
    if(numbers[k] < numbers[k-1] + numbers[k-2]):  # 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 함.
        answer = numbers[k] + numbers[k-1] + numbers[k-2]
        break
    else:
        k -= 1

print(answer)
