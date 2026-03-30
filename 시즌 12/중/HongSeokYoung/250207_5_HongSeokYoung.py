# 백준 알고리즘 10384 '팬그램' 문제
def check_pangram(sentence):
    # 알파벳 출현 횟수를 저장하는 딕셔너리 초기화
    alphabet_count = {chr(i): 0 for i in range(ord('a'), ord('z') + 1)}

    # 주어진 문장을 소문자로 변환하고 알파벳 출현 횟수 세기
    for char in sentence.lower():
        if char in alphabet_count:
            alphabet_count[char] += 1

    # 각 알파벳이 몇 번씩 등장하는지 확인
    min_count = min(alphabet_count.values())
    
    if min_count == 0:
        return "Not a pangram"
    elif min_count >= 3:
        return "Triple pangram!!!"
    elif min_count == 2:
        return "Double pangram!!"
    elif min_count == 1:
        return "Pangram!"
    
    return "Not a pangram"  # 모든 조건에 해당하지 않는 경우 기본값

# 테스트케이스 입력 받기
n = int(input())
for i in range(n):
    sentence = input().strip()
    result = check_pangram(sentence)
    print(f"Case {i + 1}: {result}")