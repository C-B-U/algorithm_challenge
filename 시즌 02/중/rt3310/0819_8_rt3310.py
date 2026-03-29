from itertools import chain, combinations, product

l, c = list(map(int, input().split()))

pw = sorted(list(map(lambda x: ord(x), input().split())))

vowel = []
consonant = []
for i in pw:
    if i == 97 or i == 101 or i == 105 or i == 111 or i == 117:
        vowel.append(i)
    else:
        consonant.append(i)

answer = []
for i in range(1, min(len(vowel)+1, l-2+1)):
    v_com = list(combinations(vowel, i))
    c_com = list(combinations(consonant, l-i))
    answer.extend(list(product(v_com, c_com)))

answer = list(map(lambda x: sorted(list(chain(*x))), answer))
answer.sort()
for i in answer:
    print(''.join(list(map(chr, i))))