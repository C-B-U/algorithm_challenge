import sys
import math
class robot:
    def __init__(self,time,No):
        self.time=time
        self.No=No
    def __it__(self,other):
        if self.time==other.time:
            return self.No<other.No
        else:
            return self.time<other.time
            

N=int(input())
robotl=[] 
for i in range(N):
    line = sys.stdin.readline().strip()
    x,y,s=map(int,line.split())
    distance=math.sqrt((x)**2+(y)**2)
    robotl.append(robot(distance/s,i+1))
robotl.sort(key=lambda x: x.time)
for i in range(N):
    print(robotl[i].No)
    
    
    