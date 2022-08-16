from sys import stdin
from collections import deque

brackets = deque(stdin.readline())
brackets.pop()
small_bracket, large_bracket = 0, 0


def error_handle():
    print(0)
    exit(0)


def do_popleft():
    if len(brackets):
        return brackets.popleft()
    else:
        error_handle()


def bracket_cal(start_bracket, value):
    if start_bracket == "(":
        multiple = 2
    else:
        multiple = 3

    bracket = do_popleft()

    while bracket == "(" or bracket == "[":
        value += bracket_cal(bracket, 0)
        bracket = do_popleft()

    if (bracket == ")" and start_bracket == "(") or (bracket == "]" and start_bracket == "["):
        if value:
            return value * multiple
        else:
            return 1 * multiple
    else:
        error_handle()


value = 0
while len(brackets):
    value += bracket_cal(brackets.popleft(), 0)
print(value)
