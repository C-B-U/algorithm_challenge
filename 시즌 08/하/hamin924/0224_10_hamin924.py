n=int(input())

text=input()

security = text.count("security")
bigdata = text.count("bigdata")

if security > bigdata:
    print("security!")
elif bigdata > security:
    print("bigdata?")
else:
    print("bigdata? security!")
