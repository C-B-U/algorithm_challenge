import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    v = list(map(int, data[2:2+n]))
    
    v.sort()
    
    sum_val = 0
    i = 0
    for j in range(n):
        sum_val += v[j] * i
        if i < k:
            i += 1
    
    print(sum_val)

if __name__ == "__main__":
    main()
