a = list(input().split(maxsplit=1))
while( a[0] != "#"):
    print(a[0],a[1].lower().count(a[0]))
    a = list(input().split(maxsplit=1))