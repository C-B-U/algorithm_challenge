n, h, s = map(float, input().split())
n = int(n)
f = list(map(int, input().split()))

if (s/n*2) <= h:
    th, sh, sum1 = (s/n*2) / n, 0.0, 0.0
    for i in range(n):
        temp = (th/2 * (i+1)) - sh
        th += (s/n*2) / n
        sh += temp
        sum1 += temp * f[i]

    th, sh, sum2 = (s/n*2) / n, 0.0, 0.0
    for i in range(n-1, -1, -1):
        temp = (th/2 * (n-i)) - sh
        th += (s/n*2) / n
        sh += temp
        sum2 += temp * f[i]
        
    print("%.6f" % min(sum1, sum2))

else:
    a = sum((h - (h - s/n)*2) * fi for fi in f)
    
    th, sh, sum1 = (h - s/n) * 2 / n, 0.0, 0.0
    for i in range(n):
        temp = th / 2 * (i + 1) - sh
        th += (h - s/n) * 2 / n
        sh += temp
        sum1 += temp * f[i]

    th, sh, sum2 = (h - s/n) * 2 / n, 0.0, 0.0
    for i in range(n - 1, -1, -1):
        temp = th / 2 * (n - i) - sh
        th += (h - s/n) * 2 / n
        sh += temp
        sum2 += temp * f[i]

    print("%.6f" % (min(sum1, sum2) + a))
