def is_palindrome(word):
    if word == word[::-1]:
        return 1
    else:
        return 0
    
word = input()
print(is_palindrome(word))