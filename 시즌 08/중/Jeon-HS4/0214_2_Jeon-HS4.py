A, B = input().split() # len(A) <= len(B)
distance = len(B) - len(A)
distance_list = []
for i in range(distance+1):
  diff = 0
  for j in range(len(A)):
    index_ = i+j
    if(B[index_] != A[j]):
      diff += 1
  distance_list.append(diff)
print(min(distance_list))
