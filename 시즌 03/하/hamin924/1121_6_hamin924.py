vowels = "aeiou"

while True:
    s = input()
    if s == "end":
        break
    v = 0 #모음의 개수
    k = 1
    for i in range(len(s)):
        if s[i] in vowels:
            v = 1
        if i > 0:
            if s[i] == s[i-1] and s[i] != 'e' and s[i] != 'o':
                k = 0
                break
        if i > 1:
            if s[i] not in vowels: #자음 연속 3개일 경우
                if s[i-1] not in vowels:
                    if s[i-2] not in vowels:
                        k = 0
                        break
            if s[i] in vowels: #모음 연속 3개일 경우
                if s[i-1] in vowels:
                    if s[i-2] in vowels:
                        k = 0
                        break
if v == 1 and k == 1:
        print("<" + s + "> is acceptable.")
else:
    print("<" + s + "> is not acceptable.")    