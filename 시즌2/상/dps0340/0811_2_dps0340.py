# https://www.acmicpc.net/problem/16934
# https://www.acmicpc.net/source/47527277

from collections import defaultdict
import sys

input = sys.stdin.readline
print = sys.stdout.write


class Trie:
    def __init__(self, s) -> None:
        self.used = False
        self.count = 0
        self.c = s
        self.children = defaultdict(lambda: Trie(""))

    def append(self, child, do_not_propagate_used=False):
        s = child.c

        if len(s) == 0:
            self.count += 1

            if self.count >= 2:
                return str(self.count)

            return ""

        c = s[0]

        is_new = False

        if self.children[c].c != c:
            self.children[c].c = c

            is_new = True

        next_ = ""

        if len(s) >= 1:
            next_ = self.children[c].append(
                Trie(s[1:]), do_not_propagate_used=do_not_propagate_used or not self.used)

        if is_new:
            if not do_not_propagate_used:
                self.used = True
            return c

        return c + next_


root = Trie("")

n = int(input().rstrip())

for i in range(n):
    name = input().rstrip()

    log = root.append(Trie(name))

    if len(log) > 0:
        print(log + "\n")
