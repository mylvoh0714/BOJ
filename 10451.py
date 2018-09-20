import sys
from collections import deque

read = sys.stdin.readline

for _ in range(int(read())): # testcase
    n = int(read())
    graph = list(map(int,read().split()))
    visited= [0 for _ in range(n)]
    graph.insert(0,0)
    visited.insert(0,0)
    ans = 0
    for i in graph:
        if i == 0 : continue

        if visited[i] is 0:
            queue = deque()
            queue.append(i)
            visited[i] = 1
            while queue:
                next = queue.popleft()
                if visited[graph[next]] is 0:
                    queue.append(graph[next])
                    visited[graph[next]] = 1
            ans += 1
    print(ans)
