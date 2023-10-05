def to_binary(octal):
    binary = ''
    while octal != 0:
        binary = str(octal % 2) + binary
        octal //= 2

    if len(binary) == 1:
        binary = '00' + binary
    elif len(binary) == 2:
        binary = '0' + binary
    
    return binary
    
a = int(input())
digits = [int(digit) for digit in str(a)]

for i in range(len(digits)):
    if i == 0:
        if digits[i] == 0:
            print('0', end='')
        else:
            b = to_binary(digits[i])
            for i in range(len(b)):
                if b[i] == '1':
                    b = b[i:]
                    break
            print(b, end='')
    else:
        print('{0:03}'.format(to_binary(digits[i])), end='')