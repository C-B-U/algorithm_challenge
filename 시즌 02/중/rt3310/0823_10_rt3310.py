t = int(input())

for _ in range(t):
    answer = 'YES'
    n = int(input())
    
    phone_book = {}
    lengths = set()
    
    for _ in range(n):
        number = input()
        phone_book[number] = 0
        lengths.add(len(number))
        
    lengths = list(lengths)

    for i in phone_book:
        for j in lengths:
            if j > len(i):
                continue
            if phone_book.get(i[:j]) is not None:
                phone_book[i[:j]] += 1

    if max(phone_book.values()) > 1:
        answer = 'NO'
    
    print(answer)