line_number = int(input())

array_number = []

for i in range(line_number):
  array_number.append(int(input()))

array_number.sort()
for i in range(line_number):
  print(f"{array_number[i]}")