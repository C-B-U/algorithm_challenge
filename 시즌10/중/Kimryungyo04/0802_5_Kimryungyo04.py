# 등차수열의 합 공식 활용
# y = (H / W)x (0 < x < W) -> N / 2 보다 왼쪽에 있는 값은 빼고 오른쪽에 있는 값은 더한 후 x2 를 해준다.

from math import ceil
W, H, N = map(int, input().split())

mid = ceil(N / 2) - 1
sum_left = mid / 2 * (2 * (H / N) + (mid - 1) * (H / N))
sum_right = (H * mid) - sum_left
length = (sum_right - sum_left) * 2
print(f"{length:.6f}")
