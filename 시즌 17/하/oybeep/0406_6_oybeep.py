N = int(input())
A = list(map(int, input().split()))

answers = []

for x in range(51):
    cnt = A.count(x)
    if cnt == x:
        answers.append(x)

if not answers:
    print(-1)
else:
    print(max(answers))
