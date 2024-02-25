n = int(input())
crane = list(map(int, input().split()))
m = int(input())
box = list(map(int, input().split()))

# ⚡ 내림차순 정렬
crane.sort(reverse = True)
box.sort(reverse = True)

time = 0 # 시간
checked = [0 for _ in range(m)] # 박스를 옮겼는지 여부
count = 0 # 옮긴 박스의 개수 

positions = [0] * n

if max(box) > max(crane):
    print(-1)
else:
    while count < len(box):
        for i in range(n): # 크레인에 대하여
            while positions[i] < len(box):
            # 아직 안 옮긴 박스 중에서, 옮길 수 있는 박스를 만날 때까지 반복
                if not checked[positions[i]] and crane[i] >= box[positions[i]]:
                    checked[positions[i]] = True
                    positions[i] += 1
                    count += 1
                    break
                positions[i] += 1
        time += 1
    print(time)    
