s = input().strip()

if 'A' in s:
    print(''.join('A' if ch in 'BCDF' else ch for ch in s))
elif 'B' in s:
    print(''.join('B' if ch in 'CDF' else ch for ch in s))
elif 'C' in s:
    print(''.join('C' if ch in 'DF' else ch for ch in s))
else:
    print('A' * len(s))
