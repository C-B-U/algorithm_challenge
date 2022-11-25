from decimal import *
 
def dist(a, b):
    return ((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])).sqrt()
 
getcontext().prec = 28
xa, ya, xb, yb, xc, yc = tuple(map(Decimal, input().split()))
a, b, c = (xa, ya), (xb, yb), (xc, yc)
la, lb, lc = dist(b, c), dist(a, c), dist(a, b) 
 
if (xb-xa)*(yc-ya) == (yb-ya)*(xc-xa):
    print(-1)
else:
    len_list = [la, lb, lc]
    print((max(len_list) - min(len_list)) * Decimal(2))
