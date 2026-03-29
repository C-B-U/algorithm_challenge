n = input()

count = {'0':0, '1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0}

for i in range(len(n)) :
  if n[i] in ['6', '9'] :
    count['6'] += 1
  else :
    count[n[i]] += 1

if count['6'] % 2 == 0:
  count['6'] = count['6'] // 2
else :
  count['6'] = count['6'] // 2 + 1

print(max(count.values()))