# 1064 : 평행사변형

ax, ay, bx, by, cx, cy = map(int, input().split())

if ((ax - bx) * (ay - cy)==(ay - by) * (ax - cx)):
    print(-1.0)
    exit(0)

ab_length = ((ax - bx)**2 + (ay - by)**2)**0.5
ac_length = ((ax - cx)**2 + (ay - cy)**2)**0.5
bc_length = ((bx - cx)**2 + (by - cy)**2)**0.5

length = [ab_length + ac_length, ab_length + bc_length, ac_length + bc_length]
result = max(length) - min(length)
print(2 * result)