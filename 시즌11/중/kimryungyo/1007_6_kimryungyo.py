# 풀이 : 브루트포스, 모든 경우를 확인해본다.

from string import ascii_lowercase
from sys import stdin
input = lambda: stdin.readline().rstrip()

asciis = list(ascii_lowercase)
ascii_idxs = { char: idx for idx, char in enumerate(asciis) }
length = len(asciis)

ENCRYPTED_STRING = input()
N = int(input())
WORDS = [ input() for _ in range(N) ]

for key in range(length):
    decryption = { char: asciis[idx - key] for char, idx in ascii_idxs.items() }

    encrypted = ENCRYPTED_STRING
    decrypted = "".join( decryption[char] for char in encrypted )

    for word in WORDS:
        if word in decrypted:
            print(decrypted)
            quit()
