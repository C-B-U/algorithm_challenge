def is_palindrome(word):
    if word == word[::-1]:
        return 1
    else:
        return 0
    
word = input("알파벳 소문자로 이루어진 단어를 입력해주세요: ")
print(is_palindrome(word))