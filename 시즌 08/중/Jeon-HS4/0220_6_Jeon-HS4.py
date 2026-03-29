def check_lucky_string(before, picked):
  if picked == len(s):
    return 1
  answer = 0
  for key in counter.keys():
    if before == key:
      continue
    if counter[key] == 0:
      continue
    counter[key] -= 1
    answer += check_lucky_string(key, picked+1)
    counter[key] += 1
  return answer

s = input()
counter = dict()
for i in range(len(s)):
  if s[i] in counter:
    counter[s[i]] += 1
  else:
    counter[s[i]] = 1

result = check_lucky_string('', 0)
print(result)
