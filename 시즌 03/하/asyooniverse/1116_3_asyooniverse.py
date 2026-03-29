# Rev(Rev(X) + Rev(Y))

def Rev(number):
    reverse = int(''.join(list(map(str, number))[::-1]))
    return reverse

number = list(map(str, input().split()))
result = str(Rev((number[0]))+Rev((number[1])))

print(Rev(result))