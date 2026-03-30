word1 = list(input())
word2 = list(input())

i = 0
while i < len(word1):
    if word1[i] in word2:   # word1의 요소가 word2에 있을 때
        word2.remove(word1[i])  # 먼저 word2에 있는 요소를 지운
        word1.remove(word1[i])  # 후에 word1에 있는 요소를 지운다.
        i -= 1                  # 길이가 1만큼 짧아졌으므로
    i += 1

print(len(word1) + len(word2))  # 같은 것을 지웠으므로 나머지 철자를 지우면 애너그램 관계에 있음.