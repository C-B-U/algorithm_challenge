N = int(input())  
F = int(input())  


def is_divisible(n, f):
    return n % f == 0


def find_smallest(n, f):
    for i in range(100):
        if is_divisible(n + i, f):
            return i


answer = find_smallest(N, F)
print("%02d" % answer)  