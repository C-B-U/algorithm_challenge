
w = input().strip()
s = input().strip()

cipher_key = ""
for char in w:
    if char not in cipher_key:
        cipher_key += char

for i in range(26):
    alphabet_char = chr(65 + i)
    if alphabet_char not in cipher_key:
        cipher_key += alphabet_char

result = ""
for char in s:

    index = ord(char) - 65
    result += cipher_key[index]


print(result)
