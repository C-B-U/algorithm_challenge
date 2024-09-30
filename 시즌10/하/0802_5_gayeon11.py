li = []
for i in range(5):
    agent = input()
    if 'FBI' in agent:
        li.append(i+1)

if len(li) > 0:
    print(*li)
else:
    print("HE GOT AWAY!")