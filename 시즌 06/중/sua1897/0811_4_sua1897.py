import sys

many = int(input())#받을 라인수 
list=[]
list2=[]
tp=()
key=[]
cnt=0
for i in range(many):
    tp=(input().split())
    list2.append(tp)
    #print(list2)
a=0
i=0
for line in list2:#한 줄마다
    for i in range(len(line)):#단어의 수만큼
        if line[i][0].lower() not in key:#대소문자 구분
            key.append(line[i][0].lower())#만약 첫글자가 단축키로 지정된다면
            line[i]='['+line[i][0]+']'+line[i][1:]# [] 넣고 덮어쓰기
            print(' '.join(line))
            break
        
    else :#첫번째 글자가 이미 지정되었다면
        for j in range(len(line)):
            a=0
            for k in range(len(line[j])):
                if line[j][k].lower() not in key:
                    key.append(line[j][k].lower())
                    line[j]=line[j][:k]+'['+line[j][k]+']'+line[j][k+1:]
                    print(' '.join(line))
                    a=1
                    break
            if a==1: break
        if a==0 :print(*line)
                        
        
        
    
