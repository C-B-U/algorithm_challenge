import math
import sys

x, y = map(int, sys.stdin.readline().rstrip().split())

sys.stdout.write(str(x+y-math.gcd(x, y)))
