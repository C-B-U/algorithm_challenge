# int fibonacci(int n){
#     if (n==0){
#     prinf("0")
#     return 0
# }
# else if (n==1){
#     prinf("1")
# return 1;
# }
# else{
# return fibonacci(n-1)+fibonacci(n-2);
# }
# }


def fibonacci(N):
    zero = [1, 0, 1]
    one = [0, 1, 1]
    if N >= 3:
        for i in range(2, N):
            zero.append(zero[i - 1] + zero[i])
            one.append(one[i - 1] + one[i])
    print(f"{zero[N]} {one[N]}")

T = int(input())
for i in range(T):
    N = int(input())
    fibonacci(N)