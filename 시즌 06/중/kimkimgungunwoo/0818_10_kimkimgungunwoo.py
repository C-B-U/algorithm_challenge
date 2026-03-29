import sys     
        
def solution(Nlist,S):
    summ=sum(Nlist)
    if summ<S:
        return 0
    summ=0
    start=-1
    end=-1
    min_l=len(Nlist)
    while(True):
        if(summ<S):
            if(end==N-1):
                break
            end+=1
            summ+=Nlist[end]
        elif(summ>=S):
            temp_l=end-start
            min_l=min(min_l,temp_l)
            start+=1
            summ-=Nlist[start]
    return min_l
    
N,S=map(int,sys.stdin.readline().rstrip().split())
Nlist=list(map(int,sys.stdin.readline().rstrip().split()))
answer=solution(Nlist,S)
print(answer)
    
        