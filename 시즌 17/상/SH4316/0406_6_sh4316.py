from collections import deque

for i in range(int(input())):
    input()
    value = input() + "--"
    length = len(value)

    queue = deque([0])
    q = 1

    next = [k for k in range(1, len(value) + 2)]
    back = [k for k in range(-1, len(value))]

    while q != 0:
        v = queue.popleft()
        q -= 1

        ###
        # abc = ""
        # print(v, queue)
        # now = 0
        # while True:
        #     v_ = next[now]
        #     if value[v_-1] == '-':
        #         break
        #     print(value[v_-1], end="")
        #     abc += str(v_-1)
        #     now = v_
        # print("")
        # print(abc)
        ###

        if value[v] == "-":
            continue
        if value[v] == "A":
            ne1 = next[v+1]
            if value[ne1-1] == "B":
                ne2 = next[ne1]
                if value[ne2-1] == "B":
                    # 링크 연결
                    ba = back[v+1]
                    ne3 = next[ne2]
                    next[ba] = ne1
                    next[ne1] = v+1
                    next[v+1] = ne3
                    back[ne3] = v+1
                    back[v+1] = ne1
                    back[ne1] = ba

                    q_ = deque()
                    for k in queue:
                        q_.append(k-1)
                    queue = q_

                    # print(True, ba, v+1, ne1, ne2, ne3)
                    if ba != -1:
                        q += 1
                        ba2 = back[ba]
                        queue.appendleft(ba2-1)
                    q += 1
                    queue.append(v)
                    continue
        if q == 0:
            ne = next[v+1]
            q += 1
            queue.append(ne-1)
    # print("done")
    now = 0
    while True:
        v = next[now]
        if value[v-1] == '-':
            break
        print(value[v-1], end="")
        now = v
    print("")
