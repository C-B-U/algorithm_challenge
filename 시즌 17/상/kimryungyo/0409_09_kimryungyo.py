# [ 풀이 ]
# 카운팅 정렬을 할 때처럼 100,000 길이의 배열을 만들고
# 각 인덱스에 해당 인덱스만큼 걸리는 곡들의 수를 저장해 세그먼트 트리를 만든다.
# 각 노드가 '곡들의 수와 총 걸리는 시간'을 저장하도록 하면
# 이분탐색으로 T 시간 내에 클리어할 수 있는 곡들의 수를 구할 수 있다.

class SegmentTree:
    def __init__(self, counts):
        self.n = len(counts) - 1
        self.count_tree = [0] * (self.n * 4)
        self.time_tree = [0] * (self.n * 4)
        self.build(counts, 1, 1, self.n)

    def build(self, counts, node, start, end):
        if start == end:
            self.count_tree[node] = counts[start]
            self.time_tree[node] = counts[start] * start
            return

        mid = (start + end) // 2
        self.build(counts, node * 2, start, mid)
        self.build(counts, node * 2 + 1, mid + 1, end)
        self.count_tree[node] = self.count_tree[node * 2] + self.count_tree[node * 2 + 1]
        self.time_tree[node] = self.time_tree[node * 2] + self.time_tree[node * 2 + 1]

    def update(self, idx, diff):
        self.change(1, 1, self.n, idx, diff)

    def change(self, node, start, end, idx, diff):
        if start == end:
            self.count_tree[node] += diff
            self.time_tree[node] += diff * start
            return

        mid = (start + end) // 2
        if idx <= mid:
            self.change(node * 2, start, mid, idx, diff)
        else:
            self.change(node * 2 + 1, mid + 1, end, idx, diff)

        self.count_tree[node] = self.count_tree[node * 2] + self.count_tree[node * 2 + 1]
        self.time_tree[node] = self.time_tree[node * 2] + self.time_tree[node * 2 + 1]

    def query(self, time):
        return self.get_count(1, 1, self.n, time)

    def get_count(self, node, start, end, time):
        if time <= 0 or self.count_tree[node] == 0:
            return 0
        if self.time_tree[node] <= time:
            return self.count_tree[node]
        if start == end:
            return min(self.count_tree[node], time // start)

        mid = (start + end) // 2
        left_time = self.time_tree[node * 2]

        if left_time > time:
            return self.get_count(node * 2, start, mid, time)
        return self.count_tree[node * 2] + self.get_count(node * 2 + 1, mid + 1, end, time - left_time)


from sys import stdin
input = stdin.readline

N, Q = map(int, input().split())
songs = list(map(int, input().split()))

counts = [0] * (100000 + 1)

for song in songs:
    counts[song] += 1

seg_tree = SegmentTree(counts)

for _ in range(Q):
    query = list(map(int, input().split()))

    # j번째 곡의 걸리는 시간을 v로 변경
    if query[0] == 1:
        _, j, v = query
        old_v = songs[j - 1]

        seg_tree.update(old_v, -1)
        seg_tree.update(v, 1)
        songs[j - 1] = v

    # T 시간 내에 클리어할 수 있는 곡들의 수
    elif query[0] == 2:
        _, T = query
        print(seg_tree.query(T))

    # 새 곡 추가
    else:
        _, v = query
        songs.append(v)
        seg_tree.update(v, 1)