s = input()
bomb = input()
st = []

for c in s:
    st.append(c)
    if len(st) >= len(bomb):
        if ''.join(st[len(st)-len(bomb):]) == bomb:
            for _ in range(len(bomb)):
                st.pop()
    
if len(st) == 0:
    print("FRULA")
else:
    print(''.join(st))