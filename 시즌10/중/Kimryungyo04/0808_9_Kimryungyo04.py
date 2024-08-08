# 아케인 스톤의 경험치 제한이 없으므로 그냥 경험치가 작은 순서대로 경험치를 더해주면 된다.
# 전체 경험치 = 해당 퀘스트의 경험치 * 활성화 된 아케인 스톤의 수

n, k = map(int, input().split())
quests = list(map(int, input().split()))
quests.sort()

exps = 0
stones = 0
for exp in quests:
    exps += exp * stones
    if stones < k: stones += 1

print(exps)
