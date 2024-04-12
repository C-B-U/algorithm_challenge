N = int(input())
dice_list = [list(map(int, input().split())) for _ in range(N)]

across_dict = {
  0 : 5,
  1 : 3,
  2 : 4,
  3 : 1,
  4 : 2,
  5 : 0
}

def cal_tot_cnt(num) :
  result = 0
  
  for i in range(N) :
    for j in range(6) :
      if dice_list[i][j] == num :
        across_num = dice_list[i][across_dict[j]]
        if 6 in [num, across_num] :
          result += 4 if 5 in [num, across_num] else 5
        else :
          result += 6
        num = across_num
        break
        
  return result

result = 0
for i in range(1, 7):
    result = max(result, cal_tot_cnt(i))
    
print(result)