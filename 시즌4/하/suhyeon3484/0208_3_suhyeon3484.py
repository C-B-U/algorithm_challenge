# 도비의 영어공부

while True:
    n = input()
    if n == '#':
        break
    alphabet = n[0]
    sentence = n[2:]
    print(alphabet, sentence.count(alphabet) + sentence.count(alphabet.upper()))