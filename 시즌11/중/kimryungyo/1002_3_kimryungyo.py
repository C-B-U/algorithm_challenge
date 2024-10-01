# 실버 3 치고 생각보다 어렵다 싶었는데 A는 N의 약수라는 조건이 있었구나.. 역시 항상 지문은 꼼꼼히
# 풀이 : 그냥 순서대로 돌아가면서 물을 주면 된다

N, K, A, B = map(int, input().split())
pots = [ K ] * N

day = 0
idx = 0
while True:
    day += 1

    for i in range(idx, idx + A):
        pots[i] += B

    for i in range(N):
        pots[i] -= 1
        if pots[i] == 0:
            print(day)
            quit()

    idx += A
    if idx == N:
        idx = 0
