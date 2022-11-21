vowels = ["a", "e", "i", "o", "u"]

while True:
    flag = True
    vowel_check = False
    temp = ""
    c = 0
    v = 0
    string = input()
    if string == "end":
        break
    for i in string:
        # 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
        if i in vowels:
            # 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            vowel_check = True
            v = v + 1
            c = 0
            if v == 3:
                flag = False
                break
            # 3.
            if temp == i:
                if i == "e" or i == "o":
                    continue
                flag = False
                break

        else:
            # 2-2. 자음 3번 연속
            c = c + 1
            v = 0
            if c == 3:
                flag = False
                break
            # 3.
            if temp == i:
                if i == "e" or i == "o":
                    continue
                flag = False
                break
        
        temp = i

    if vowel_check and flag:
        print(f"<{string}> is acceptable.")     
    else:
        print(f"<{string}> is not acceptable.")             