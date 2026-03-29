import re

N = int(input())
answers = input()

bigdata_count = len(re.findall('bigdata', answers))
security_count = len(re.findall('security', answers))

if bigdata_count > security_count:
    print("bigdata?")
elif bigdata_count < security_count:
    print("security!")
else:
    print("bigdata? security!")