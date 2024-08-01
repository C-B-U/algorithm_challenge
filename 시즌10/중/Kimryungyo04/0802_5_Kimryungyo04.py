# 등차수열의 합 공식 활용

from math import ceil
W, H, N = map(int, input().split())
diff = H / N

mid = ceil(N / 2) - 1
sum_a = mid / 2 * (2 * diff + (mid - 1) * diff)
sum_b = (H * mid) - sum_a
length = (sum_b - sum_a) * 2
print(f"{length:.6f}")
