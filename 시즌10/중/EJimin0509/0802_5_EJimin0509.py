def ladder_length(W, H, N):
    result = 0
    
    if (N % 2) == 0:
        result = (N-2) / 4
    else:
        result = (N-1)*(N-1) / (4*N)
    
    return result*2*H

W, H, N = map(int, input().split())

result = ladder_length(W, H, N)

print(f"{result:.6f}")
