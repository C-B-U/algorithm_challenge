n = int(input())
keys = []

for i in range(n):
    word = input()
    words = word.split()
    newkey = -1

    for j in range(len(words)):
        if (words[j][0].upper() not in keys):
            keys.append(words[j][0].upper())
            if(j == 0):
                newkey = 0
            else:
                newkey = 0
                for _ in range(j):
                    newkey += len(words[_]) + 1
            print(word[:newkey] + '[' + word[newkey] + ']' + word[newkey + 1:])
            break

    if newkey == -1:
        for k in range(len(word)):
            if (word[k].upper() not in keys and word[k] != ' '):
                keys.append(word[k].upper())
                newkey = k
                print(word[:newkey] + '[' + word[newkey] + ']' + word[newkey + 1:])
                break

    if newkey == -1:
        print(word)
