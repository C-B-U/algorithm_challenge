import sys

N = int(sys.stdin.readline())

Options = []
HotKeys = []


def get_Hotkey(option: str, words: list[str], fronts: list[str]):
    for number, front in enumerate(fronts):
        if front not in HotKeys:
            words[number] = f'[{words[number]}'
            words[number] = f'{words[number][:2]}]{words[number][2:]}'
            option = ' '.join(words)
            return option, front

    for n, word in enumerate(words):
        word = word.lower()
        for number, alphaebt in enumerate(word[1:]):
            if alphaebt not in HotKeys:
                words[n] = f'{words[n][:number+1]}[{words[n][number+1]}]{words[n][number + 2:]}'
                option = ' '.join(words)
                return option, alphaebt

    return option.rstrip(), None


for i in range(N):
    Options.append(str(sys.stdin.readline()))

for option in Options:
    words = option.split()

    fronts = [word[0].lower() for word in words]
    option, temp = get_Hotkey(option, words, fronts)
    HotKeys.append(temp)
    print(option)
