import sys
str_list = [sys.stdin.readline() for _ in range(50)]
word_dict = {}

str_list = list(filter(None, str_list))
input_str = ''.join(str_list)

for strs in input_str:
    if strs == ' ' or strs == '\n': continue
    else :
        if strs in word_dict:
            word_dict[strs] += 1
        else:
            word_dict[strs] = 1

word_max = max(word_dict.values())

for strs, word in sorted(word_dict.items()):
    if word == word_max:
        print(strs, end='')