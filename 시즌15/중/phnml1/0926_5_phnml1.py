import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = list(map(int,input().split()));
r = max(arr);
l = 0;
result = 0;
sum_arr = sum(arr);
while l<=r:
    mid = (l+r)//2;
    cur_arr = [];
    for num in arr:
        cur_arr.append(num - mid if num>mid else 0)
    res = sum(cur_arr);
    if m<=res:
        result = mid;
        l = mid+1;
    else:
        r = mid-1;
print(result);