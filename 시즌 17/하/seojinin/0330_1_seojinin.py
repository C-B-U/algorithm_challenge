s = input()

if 'A' in s:
    for ch in ['B', 'C', 'D', 'F']:
        s = s.replace(ch, 'A')

elif 'B' in s:
    for ch in ['C', 'D', 'F']:
        s = s.replace(ch, 'B')

elif 'C' in s:
    for ch in ['D', 'F']:
        s = s.replace(ch, 'C')

else:
    s = 'A' * len(s)

print(s)
