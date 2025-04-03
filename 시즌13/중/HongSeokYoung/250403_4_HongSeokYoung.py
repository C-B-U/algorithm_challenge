# 백준 알고리즘 1614번 '영식이의 손가락' https://www.acmicpc.net/problem/1614

Hurt_Finger = int(input())
Value = int(input())

if Hurt_Finger == 1:
    result = 8 * Value

elif Hurt_Finger == 5:
    result = 8 * Value + 4

elif Value % 2 == 0:
    result = 4 * (Value + 1) - (5 - Hurt_Finger)

else:
    result = 4 * (Value + 1) - Hurt_Finger + 1

print(result)