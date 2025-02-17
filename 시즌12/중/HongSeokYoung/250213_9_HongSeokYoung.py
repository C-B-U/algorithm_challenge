#백준 알고리즘 1254 '팰린드롬 만들기' 문제
def is_palindrome(s):
    return s == s[::-1]

def min_palindrome_length(S):
    for i in range(len(S)):
        if is_palindrome(S[i:]):
            return len(S) + i  # 앞부분을 뒤집어서 추가하면 됨
    return 2 * len(S) - 1  # 모든 문자가 다 달라서 최악의 경우

S = input().strip()
print(min_palindrome_length(S))