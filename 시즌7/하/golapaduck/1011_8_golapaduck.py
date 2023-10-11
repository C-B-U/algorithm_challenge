count = int(input())
for i in range(1,2*count):
    print(' ' * abs(i-count),end='')
    print('*' * (2*count-1-2*abs(i-count)))