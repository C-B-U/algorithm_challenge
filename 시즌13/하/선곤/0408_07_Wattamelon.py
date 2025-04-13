n = int(input())
letters = []
for _ in range(n):
    letters.append(input())

for letter in letters:
    print(f"{letter[0]}{letter[-1]}")
