n1, n2 = map(int, input().split())
a = [*input()]
b = [*input()]
t = int(input())

ans = a[::-1] + b
for i in range(t):
    for j in range(len(ans)-1):
        if ans[j] in a and ans[j+1] in b:
            ans[j], ans[j+1] = ans[j+1], ans[j]
            if ans[j+1] in a[0]:
                break


print("".join(ans))
