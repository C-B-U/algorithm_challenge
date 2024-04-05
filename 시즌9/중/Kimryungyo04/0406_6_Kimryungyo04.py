def calculate_period(m):
    fibonacci = [1, 1]
    for i in range(int(1e10)):
        remainder = (fibonacci[0] + fibonacci[1]) % m
        fibonacci = [fibonacci[1], remainder]
        if fibonacci == [1, 1]: break
    return i + 1

def main():
    num_tests = int(input())
    for i in range(num_tests):
        num, m = map(int, input().split())
        print(num, calculate_period(m))

main()