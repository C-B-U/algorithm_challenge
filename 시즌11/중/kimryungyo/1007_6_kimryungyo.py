# 풀이 : 브루트포스, 모든 경우를 확인해본다.
# 생각없이 짰더니 너무 비효율적이어서 수정 (10.12)

ENCRYPTED = input()
N = int(input())
WORDS = [ input() for _ in range(N) ]

for key in range(26):
    decrypted = "".join( chr((97 + ((ord(char) - 97) + key) % 26)) for char in ENCRYPTED )

    if any(word in decrypted for word in WORDS):
        print(decrypted)
        quit()

# 하는김에 숏코딩도
E,N,*W=open(0).read().split()
for k in range(26):
 if any(w in(d:=''.join(chr((ord(c)+k-97)%26+97)for c in E))for w in W):print(d);quit()
