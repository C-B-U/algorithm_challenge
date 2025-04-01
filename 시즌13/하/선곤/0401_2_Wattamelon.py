"""n = 9 
numbers = [1]
ans = [1]


print("n e")
print("- -----------")

for i in range(0,n+1):
    if i==0:
        print("%d %d"%(i,ans[-1]))
    elif i == 1:
        a = numbers[-1]*i
        ans.append(round(ans[-1]+(1/a),9))
        numbers.append(a)
        print("%d %d"%(i,ans[-1]))
    elif i == 2:
        print(i, end=" ")
        print(round(ans[-1],9))
    else:
        a = numbers[-1]*i
        ans.append(ans[-1]+(1/a))
        numbers.append(a)
        print("%d %.9f" %(i,ans[-1]))"""

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


        


