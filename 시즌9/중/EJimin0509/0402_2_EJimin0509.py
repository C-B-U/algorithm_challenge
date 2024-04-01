while True:
    n = int(input())
    if n == 0:
        break
    
    charge = []
    for _ in range(n):
        charge.append(int(input()))

    charge.sort()

    answer = "POSSIBLE"
    for i in range(len(charge) - 1):
        if charge[i + 1] - charge[i] > 200:
            answer = "IMPOSSIBLE"
            break

    if 1422 - charge[-1] > 100:
        answer = "IMPOSSIBLE"
    print(answer)