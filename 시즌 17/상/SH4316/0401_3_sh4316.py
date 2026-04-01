a, b = map(int, input().split(' '))
c, d = map(int, input().split(' '))
k = int(input())

n = 0
if k != 0:
    n = b // k
    if b % k > 0:
        n += 1
else:
    n = a // b
    if a % b > 0:
        n += 1

start = 1
end = n

# print(start, end)

while start < end:
    mid = (start + end) // 2
    val = (b*mid - k*(mid-1)*mid//2)
    # print(":", mid, val)
    if val < a:
        start = mid + 1
    elif val == a:
        end = mid
        break;
    else:
        end = mid
if (b*end - k*(end-1)*end//2)  >= a:
    n = end
else:
    n = end + 1


m1 = (b*n - k*(n-1)*n//2)
m2 = d * n - (c)


# print(end)
# print(n)
# print(m1)
# print(m2)

if m1 < a:
    print(-1)
elif m1 >= a and m2 >= a:
    print(-1)
elif m2 >= m1:
    print(-1)
else:
    print(n)
