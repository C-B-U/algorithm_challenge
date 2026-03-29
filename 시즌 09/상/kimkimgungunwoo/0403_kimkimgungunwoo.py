def clear(answer,stack,inp):
    string=answer
    while len(stack)>0 and ddict[stack[-1]]<=ddict[inp]:
        st=stack[-1]
        if st!="(":
            string+=stack.pop()
        else:
            if inp==")":
                stack.pop()
            break
        
    return string
 
 
ddict={"+":2,"-":2,"*":1,"/":1,"(":0,")":4}
M=input()
answer=""
stack=[]
for i in range(len(M)):
    if M[i] not in ddict:
        answer+=M[i]
    else:
        if len(stack)>0 :
            if ddict[stack[-1]]>ddict[M[i]]:
                stack.append(M[i])
            else:
                answer=clear(answer,stack,M[i])
                if M[i]!=")":
                    stack.append(M[i])
        else:
            stack.append(M[i])
while len(stack)>0:
    answer+=stack.pop()
    
print(answer)