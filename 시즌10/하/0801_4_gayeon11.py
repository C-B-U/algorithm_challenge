# quarter = $0.25
# dime = $0.10
# nickel = $0.05
# penny = $0.01

T = int(input())
for i in range(T):
    Q = 0
    D = 0
    N = 0
    P = 0
    
    c = int(input())
    
    while True:
        if(c >= 25): 
            c = c-25
            Q += 1
        elif(c >= 10):
            c = c-10
            D += 1
        elif(c >= 5):
            c = c-5
            N += 1
        elif(c >= 1): 
            c = c-1
            P += 1
        else: 
            break
    
    print(Q, D, N, P)
