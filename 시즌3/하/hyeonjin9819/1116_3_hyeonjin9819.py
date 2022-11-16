data = list(map(int, input().split()))

first = int(str(data[0])[::-1])
sec = int(str(data[1])[::-1])
pre = first + sec
ans = int(str(pre)[::-1])
print(ans)