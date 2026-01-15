a_val = None
b_val = None

# A 찾기 (최대 9번)
for a in range(1, 10):
    print("? A", a, flush=True)
    resp = int(input().strip())
    if resp == 1:
        a_val = a
        break

# B 찾기 (최대 9번)
for b in range(1, 10):
    print("? B", b, flush=True)
    resp = int(input().strip())
    if resp == 1:
        b_val = b
        break

# 정답 출력 (질문 횟수에 포함 X)
print("!", a_val + b_val, flush=True)
