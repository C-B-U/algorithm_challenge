a = input().rstrip()
arr = a.split('-');
result = 0;
if a[0] == '-':
  arr[0] = '-' +arr[0]

for i in range(len(arr)):
    numbers = list(map(int, arr[i].split('+')))
    result = result + sum(numbers) if i ==0 else result - sum(numbers);
print(result);