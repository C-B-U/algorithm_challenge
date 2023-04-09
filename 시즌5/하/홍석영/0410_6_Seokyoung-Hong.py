k, l = map(int, input().split())


def is_good_pw(k, l):
    min = l+1
    if k > l:
        for i in range(l, 1, -1):
            if k % i == 0:
                min = i

    return "GOOD" if min >= l else f"BAD {min}"


print(is_good_pw(k, l))
