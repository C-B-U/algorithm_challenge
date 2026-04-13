import sys
input=sys.stdin.readline

N,m=map(int,input().split())

dur1=N
dur2=N//2
dur3=(N+1)//2
dur4=(N+2)//3
result=set()

for b1 in [0,1]:
    for b2 in [0,1]:
        for b3 in [0,1]:
            for b4 in [0,1]:

                state=[]
                time = b1 * dur1 + b2 * dur2 + b3 * dur3 + b4 * dur4
                if time>m:
                    continue

                for floor in range(1, N+1):
                    cur = 1

                    if b1:
                        cur^=1

                    if b2 and floor % 2 == 0:
                        cur^=1

                    if b3 and floor % 2 == 1:
                        cur^=1

                    if b4 and floor % 3 == 1:
                        cur^=1

                    state.append(cur)
                result.add(tuple(state))
print(len(result))