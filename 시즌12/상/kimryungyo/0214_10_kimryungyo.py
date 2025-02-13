# [ 풀이 ] - 재귀
# 대표적인 재귀 문제
#
# 출력할 내용이 많기 때문에 결과를 한 줄씩 출력하지 않고
# 하나의 문자열로 만들어 한번에 출력하면 유의미한 시간 단축이 가능하다

def hanoi(n, start, end, moves):
    if n == 1:
        moves.append((start, end))
    else:
        aux = 6 - start - end
        hanoi(n - 1, start, aux, moves)
        moves.append((start, end))
        hanoi(n - 1, aux, end, moves)

def print_answer(moves):
    print(len(moves))
    print("\n".join(f"{a} {b}" for a, b in moves))

n = int(input().strip())
moves = []
hanoi(n, 1, 3, moves)
print_answer(moves)