x = int(input().strip())  # 용의자 수
count = 0                 # 'S'가 들어간 용의자 수
answer = ""               # 'S'가 들어간 이름 저장

for _ in range(x):
    name = input().strip()

    if 'S' in name:       # 이름에 'S'가 포함되면
        answer = name
        count += 1

if count == 1:
    print(answer)
