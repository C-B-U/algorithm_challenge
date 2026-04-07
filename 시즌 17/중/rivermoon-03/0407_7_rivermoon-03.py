import sys
input = sys.stdin.readline
# 그냥 문제대로 풀면 시간초과

s = input().strip()
t = input().strip()
t_list = list(t)

# T의 길이가 S의 길이와 같아질 때까지
while len(t_list) > len(s):
    # T의 맨 마지막 글자를 확인
    if t_list[-1] == 'A':
        # 원래 : 문자열 뒤에 A를 추가한다.
        # 역 : 맨 뒤의 A를 제거한다.
        t_list.pop()
        
    elif t_list[-1] == 'B':
        # 원래 : 문자열을 뒤집고 뒤에 B를 추가한다.
        # 역 : 맨 뒤의 B를 제거하고, 문자열을 다시 뒤집는다.
        t_list.pop()
        t_list.reverse()
        
# 합치면 S와 같음?
print(1) if "".join(t_list) == S else print(0)
