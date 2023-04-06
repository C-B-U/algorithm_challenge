n = input()
count = [n.count(str(i)) for i in range(10)]
count[6] = sum(divmod(count[6]+count[9],2))
print(max(count[:-1]))
