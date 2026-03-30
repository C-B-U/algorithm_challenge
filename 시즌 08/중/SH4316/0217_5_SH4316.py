# 뻘짓 하다 풀이 찾아보고서야 간단한 문제라는걸 깨달았어요..
# 하루가 사라졌ㅇ...


# n = int(input())

# value = []
# select = []

# def low(t):
#     low = 10000
#     result = -1
#     for i in range(3):
#         if t[i] < low:
#             result = i
#             low = t[i]
#     return result
    
    
# def getDiff(index, selection, newSelection):
#     targetValue = value[index]

#     return targetValue[newSelection] - targetValue[selection]

# def getMinDiff(index, selection):
#     # selection = select[index]
#     targetValue = value[index]

#     newSelection = [(selection + 1) % 3, (selection + 2) % 3]

#     if index == 0:
#         v1 = getDiff(index, selection, newSelection[0])
#         v2 = getDiff(index, selection, newSelection[1])
#         if v1 < v2:
#             return [[newSelection[0]], v1]
#         else:
#             return [[newSelection[1]], v2]
#     # print(selection, newSelection)
        

#     results = []

#     for s in newSelection:
#         if select[index-1] != s:
#             results.append([[s], getDiff(index, selection, s)])
#         else:
#             subDiff = getMinDiff(index-1, s)
#             results.append([[s] + subDiff[0], getDiff(index, selection, s) + subDiff[1]])
    
    
#     results.append(getMinDiff(index-1, select[index-1]))

#     print(results)

#     minDiff = 10000000
#     minIndex = -1
#     for i, r in zip(range(3), results):
#         if minDiff > r[1]:
#             minDiff = r[1]
#             minIndex = i
#     return results[minIndex]




# for i in range(n):
#     s = input().split(" ")
#     t = (int(s[0]), int(s[1]), int(s[2]))
#     value.append(t)
#     index = low(t)
#     select.append(index)
#     if (i == 0):
#         continue
#     if select[i-1] == select[i]:
#         # print("called index:", i)
#         diff = getMinDiff(i, index)
#         print("\n", diff)
#         ii = i
#         for j in diff[0]:
#             select[ii] = j
#             ii -= 1

# sum = 0
# for v in zip(value, select):
#     sum += v[0][v[1]]
#     print(v[0][v[1]])
# print(sum)

import copy

n = int(input())
# values = []
cost = []
sortedIndex = []

def getSortedIndex(value):
    index = []
    for i, v in zip(range(len(value)), value):
        continue_ = False
        for j in range(len(index)):
            if value[index[j]] > v:
                index.insert(j, i)
                continue_ = True
                break
        if continue_:
            continue
        index.append(i)
    return index

for i in range(n):
    s = input().split(" ")
    v = (int(s[0]), int(s[1]), int(s[2]))
    si = getSortedIndex(v)
    if (i == 0):
        cost.append(v)
        sortedIndex.append(si)
        continue
    c = []
    for i in range(3):
        if (sortedIndex[-1][0] == i):
            c.append(cost[-1][sortedIndex[-1][1]] + v[i])
            continue
        c.append(cost[-1][sortedIndex[-1][0]] + v[i])
    cost.append(c)
    sortedIndex.append(getSortedIndex(c))

# print()

# print(cost)

# print()

# for i, c in zip(sortedIndex, cost):
#     print(c[i[0]])

print(cost[-1][sortedIndex[-1][0]])







