n, m = map(int, input().split())

t1 = n
t2 = n // 2
t3 = (n + 1) // 2
t4 = (n - 1) // 3 + 1

limit = min(n, 6)
results = set()

for b1 in range(2):
    for b2 in range(2):
        for b3 in range(2):
            for b4 in range(2):
                total = 0
                state = [1] * limit

                if b1:
                    total += t1
                    for i in range(limit): state[i] = 1 - state[i]
                if b2:
                    total += t2
                    for i in range(1, limit, 2): state[i] = 1 - state[i]
                if b3:
                    total += t3
                    for i in range(0, limit, 2): state[i] = 1 - state[i]
                if b4:
                    total += t4
                    for i in range(0, limit, 3): state[i] = 1 - state[i]

                if total <= m:
                    results.add(tuple(state))

print(len(results))