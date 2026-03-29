while True:
    n = int(input())
    divisor_list = []
    total = 0

    for i in range(1, n):
        if n % i == 0:
            divisor_list.append(i)
            total += i

    if n == -1:
        break
    elif n == total:
        print(f"{n} = {" + ".join(str(i) for i in divisor_list)}")
    else:
        print(f"{n} is NOT perfect.")