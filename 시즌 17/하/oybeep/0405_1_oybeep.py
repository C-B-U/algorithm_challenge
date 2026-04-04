S = input()

if 'A' in S:
    result = ''.join(['A' if c in ['B', 'C', 'D', 'F'] else c for c in S])

elif 'B' in S:
    result = ''.join(['B' if c in ['C', 'D', 'F'] else c for c in S])

elif 'C' in S:
    result = ''.join(['C' if c in ['D', 'F'] else c for c in S])

else:
    result = 'A' * len(S)

print(result)
