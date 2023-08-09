import sys


n = int(sys.stdin.readline())  # 입력 횟수를 읽음
string_array = []

for _ in range(n):
    input_string = sys.stdin.readline().rstrip()  # 문자열을 읽어들임
    string_array.append(input_string.split())  # 문자열을 공백을 기준으로 분리하여 이중 배열에 추가
dlist=[] #단축키 넣어 둘 리스트

for i in range(n):
    for j in range(len(string_array[i])):
        checkf=0
        checkch=string_array[i][j][0]
        if(checkch.lower() in dlist):
            checkf=1
        if(checkf!=1):
            dlist.append(checkch.lower())
            index_to_insert = string_array[i][j].index(checkch)  # checkch가 처음 나오는 인덱스
            string_array[i][j] = (
                string_array[i][j][:index_to_insert]
                + "["
                + string_array[i][j][index_to_insert]
                + "]"
                + string_array[i][j][index_to_insert + 1 :]
            )  # 인덱스를 기준으로 문자열을 조합
            break
    if checkf==1:
        for j in range(len(string_array[i])):
            check_l=0
            for z in range(len(string_array[i][j])):
                if not string_array[i][j][z].lower() in dlist:
                    checkch=string_array[i][j][z]
                    dlist.append(checkch.lower())
                    index_to_insert = string_array[i][j].index(checkch)
                    string_array[i][j] = (
                    string_array[i][j][:index_to_insert]
                    + "["
                    + string_array[i][j][index_to_insert]
                    + "]"
                    + string_array[i][j][index_to_insert + 1 :]
                    ) 
                    check_l=1
                    break
            if check_l==1:
                break
for i in range(n):
    print(" ".join(string_array[i]))

 
        
        