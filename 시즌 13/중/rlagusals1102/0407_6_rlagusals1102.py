map(int, input().split())
g1,g2 = input(), input()

ants = [(i, 'L') for i in reversed(g1)] + [(i, 'R') for i in g2]

for _ in range(int(input())):
    i = 0
    while i < len(ants) - 1:
        if ants[i][1] == 'L' and ants[i+1][1] == 'R':
            ants[i], ants[i+1] = ants[i+1], ants[i]
            i += 2
        else:
            i += 1

print(''.join([i for i, _ in ants]))
