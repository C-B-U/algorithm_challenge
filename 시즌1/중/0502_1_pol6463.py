import sys


inputNum = int(sys.stdin.readline())
num = 1
degree = 1


while(num < inputNum):
    num += 6 * degree
    degree += 1

sys.stdout.write(str(degree)+ "\n")
