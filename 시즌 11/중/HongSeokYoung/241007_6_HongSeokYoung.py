# 백준 알고리즘 14584 '암호 해독' 문제

from string import ascii_lowercase

# 알파벳 리스트 생성
alphabets = list(ascii_lowercase)

# 암호문 입력 받기
s = input()
# 사전 단어 개수와 단어 입력 받기
dictionary = [input() for _ in range(int(input()))]

# 사전 내의 단어가 포함된 해독문이 출력되었는지 확인하는 변수
found = False

# 먼저 암호문에 사전 단어가 있는지 확인
for word in dictionary:
    if word in s:
        print(s)
        found = True
        break

# 암호문에 사전 단어가 없을 경우 한 칸씩 시프트하며 해독 시도
if not found:
    for i in range(1, 26):  # 1부터 25까지 시프트 시도
        shift_dict = {alphabets[j]: alphabets[(j + i) % 26] for j in range(26)}
        decoded = ''.join(shift_dict.get(char, char) for char in s)
        
        # 해독된 문자열에 사전 단어가 포함되면 출력
        for word in dictionary:
            if word in decoded:
                print(decoded)
                found = True
                break
        if found:
            break