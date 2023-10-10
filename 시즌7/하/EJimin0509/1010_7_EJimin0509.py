num_str = input()
num = [int(nums) for nums in num_str.split()]
print(abs((num[0]+num[3])-(num[1]+num[2])))