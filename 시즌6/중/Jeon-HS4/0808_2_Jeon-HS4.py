finger = int(input())
number = int(input())

numberList = [1,2,3,4,5,4,3,2]  # 반복하는 경우를 배열로 설정
count = 0

if(finger in [1,5]):  # numberList 배열에서 1, 5는 1번, 나머지는 2번씩 카운트 됨.
    repleCount = 1
else:
    repleCount = 2

# 다친 손가락을 사용해서 최대한 배열에 맞게 숫자를 세도록 함
count += (number//repleCount)*8
# 다친 손가락을 모두 사용한 마지막 숫자세기 상태로 변환
number = number%repleCount

# 순서대로 배열을 돌면서 다친 손가락을 사용하지 못하는 경우까지 반복.
for i in numberList:
    if(i == finger):
        number -= 1
        if(number < 0):  # number == 0 인 경우에도 멀쩡한 숫자는 셀 수 있기 때문에 < 0 으로 설정
            break
    count += 1
  
print(count)

# 아래 for문을 while 반복 안에 넣고 코드를 작성한 결과, 불필요한 연산이 다수 발생하여 시간초과를 일으킴
# 시간을 단축시키기 위해 number의 경우를 1 또는 0으로 낮춰 for문을 한번만 돌아도 답이 나오도록 함.
