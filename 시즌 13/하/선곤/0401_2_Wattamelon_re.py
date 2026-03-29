
def fac(n):
    if n<=1:
        return 1
    return n*fac(n-1)

def ans(n , sum):
    return sum + (1/(sum+n))

fac_nums = []
sum = 0

print("n e")
print("- -----------")

for i in range(10):

    if i == 0 or i == 1:
        fac_nums.append(fac(i))
        sum += 1/fac_nums[-1]
        print("%d %d"%(i,sum))
    elif i == 2:
        fac_nums.append(fac(i))
        sum += 1/fac_nums[-1]
        print(i, end=" ")
        print(round(sum,9))
    else:
        fac_nums.append(fac(i))
        sum += 1/fac_nums[-1]
        print("%d %.9f" %(i,sum))


        


