n = int(input())
using_key = [0] * 26 # 사용중인 키 저장
org_str = [""] * n  # 입력 원본
options = [0] * n  # 복사본

for i in range(n):
    org_str[i] = input()
    options[i] = (org_str[i].lower()).split(' ') # 공백을 기준으로 리스트화와 동시에 소문자로 변경
    op1_index, op2_index = 0, 0 # 키의 위치 저장용
    op1, op2 = False, False # 옵션 충족 여부
    for j in options[i]:
        if not op1:
            if using_key[ord(j[0]) - 97] == 0: # 옵션 1 충족
                tmp = j[0] # 키 저장
                op1 = True
                break # 연산 종료
            elif not op2:
                op2_index = op1_index # 옵션 2의 키 인덱스 조정
                for k in j: # 알파벳 하나씩 조회
                    if using_key[ord(k) - 97] == 0: # 옵션 2 충족
                        tmp = k # 키 저장
                        op2 = True
                        break # 옵션 2 종료
                    op2_index += 1
        op1_index += len(j) + 1 # 옵션 1의 키 인덱스 조정
    using_key[ord(tmp) - 97] = 1 # 해당 키 사용 중 기록
    if op1:
        org_str[i] = org_str[i][:op1_index] + '[' + org_str[i][op1_index] + ']' + org_str[i][op1_index + 1:]
    elif op2:
        org_str[i] = org_str[i][:op2_index] + '[' + org_str[i][op2_index] + ']' + org_str[i][op2_index + 1:]

for i in org_str:
    print(i)
