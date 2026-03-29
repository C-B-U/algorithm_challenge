import sys
input = sys.stdin.read
from collections import namedtuple

Memo = namedtuple('Memo', ['week', 'day', 'price'])

def main():
    data = input().split()
    index = 0
    
    n = int(data[index])
    index += 1
    
    memo_dict = {}
    for _ in range(n):
        s = data[index]
        w = int(data[index+1])
        d = int(data[index+2])
        p = int(data[index+3])
        memo_dict[s] = Memo(w, d, p)
        index += 4
    
    for _ in range(n):
        s = data[index]
        m = int(data[index+1])
        index += 2
        if memo_dict.get(s).price > m:
            del memo_dict[s]
    
    visit = [[False] * 7 for _ in range(11)]
    for memo in memo_dict.values():
        visit[memo.week][memo.day] = True
    
    max_streak = 0
    current_streak = 0
    
    for week in range(1, 11):
        for day in range(7):
            if visit[week][day]:
                current_streak += 1
            else:
                if current_streak > 0:
                    max_streak = max(max_streak, current_streak)
                    current_streak = 0
    
    max_streak = max(max_streak, current_streak)
    
    print(max_streak)

if __name__ == "__main__":
    main()
