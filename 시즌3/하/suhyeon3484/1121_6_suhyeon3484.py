# 4659 : 비밀번호 발음하기

vows = "aeiou"

while True:
    password = input()

    if password == 'end':
        break
    
    v = 0 
    k = 1    

    for i in range(len(password)):
        if password[i] in vows:
            v = 1
        if i > 0:
            # 같은 문자 연속 2개 오면 안되지만 e,o는 예외
            if password[i] == password[i - 1] and password[i] != 'e' and password[i] != 'o':
                k = 0
                break
        if i > 1:
            # 자음 3번 연속
            if password[i] not in vows:
                if password[i - 1] not in vows:
                    if password[i - 2] not in vows:
                        k = 0
                        break
            # 모음 3번 연속
            if password[i] in vows:
                if password[i - 1] in vows:
                    if password[i - 2] in vows:
                        k = 0
                        break

    if v == 1 and k == 1:
        print(f'<{password}> is acceptable.')
    else:
        print(f'<{password}> is not acceptable.')

