def is_Prime(n):
    if n == 1 or n == 2:
        return True
    elif n % 2 == 0:
        return False
    for i in range(3,int(n**(1/2))+2,2):
        if n%i == 0:
            return False
    return True

string = input()
sum = 0
for s in string:
    if s.isupper():
        sum += ord(s)-38
    else:
        sum += ord(s)-96

if is_Prime(sum):
    print("It is a prime word.")
else:
    print("It is not a prime word.")
