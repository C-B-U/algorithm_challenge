D, H, W = map(int, input().split())
a=D/((W**2+H**2)**0.5)
print(int(H*a), int(W*a))