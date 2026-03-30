s = input().strip()

if 'A' in s:
    s = s.replace('B', 'A')
    s = s.replace('C', 'A')
    s = s.replace('D', 'A')
    s = s.replace('F', 'A')
elif 'B' in s:
    s = s.replace('C', 'B')
    s = s.replace('D', 'B')
    s = s.replace('F', 'B')
elif 'C' in s:
    s = s.replace('D', 'C')
    s = s.replace('F', 'C')
else:
    s = 'A' * len(s)

print(s)
