k = int(input())             

n = (1 << k) - 1             # 2^k - 1 (1부터 n까지 더해야 함).
total = n * (n + 1) // 2     # 1부터 n까지의 합 공식. 

binary = bin(total)[2:]      # 이진수로 변환 후, '0b' 제거.

print(binary)
