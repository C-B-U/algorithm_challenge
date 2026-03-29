n = int(input())

calc_counts = [0] * n+1
for i in range(2, n+1):
  calc_counts[i] = calc_counts[i-1] + 1
  if(i%2 == 0):
    calc_counts[i] = min(calc_counts[i], calc_counts[i//2] + 1)
  if(i%3 == 0):
    calc_counts[i] = min(calc_counts[i], calc_counts[i//3] + 1)

print(calc_counts[n])
