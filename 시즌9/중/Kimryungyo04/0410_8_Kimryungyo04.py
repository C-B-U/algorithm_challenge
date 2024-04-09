with open("input.md") as f: inputs = f.read()
inputs = list(inputs.strip().split("\n"))
def input(): return inputs.pop(0)


directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
paths = []
for d1 in directions :
    for d2 in directions:
        for d3 in directions:
            for d4 in directions:
                for d5 in directions:
                    paths.append((d1, d2, d3, d4, d5))

world = []
for i in range(5): world.append(input().split())

def get_numbers(x, y, path):
    number = world[x][y]
    for step in path:
        if 0 <= (x := x + step[0]) <= 4 and 0 <= (y := y + step[1]) <= 4:
            number += world[x][y]
        else: return None
    return number

numbers = set()
for x in range(5):
    for y in range(5):
        for path in paths:
            if (result := get_numbers(x, y, path)) != None:
                numbers.add(result)

print(len(numbers))