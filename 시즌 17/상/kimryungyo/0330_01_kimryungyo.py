# K번째 수는 (K + 1)을 이진수로 썼을 때 맨 앞 1을 제거한 뒤 0은 4, 1은 7로 바꾸면 된다.
K = int(input())
bits = bin(K + 1)[3:]
answer = bits.replace("0", "4").replace("1", "7")
print(answer)