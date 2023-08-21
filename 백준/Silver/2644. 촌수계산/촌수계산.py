# BOJ_2644 : 촌수 계산
import sys


def bfs(g, start, end):
    global visited
    queue = [start]
    visited[start] = 0
    while queue:
        pos = queue.pop(0)
        distance = visited[pos]
        if pos == end:
            break
        for n_pos in g[pos]:
            if visited[n_pos] == -1:
                queue.append(n_pos)
                visited[n_pos] = distance + 1
    return visited[end]


n_people = int(sys.stdin.readline())
p1, p2 = map(int, sys.stdin.readline().split())
n_edges = int(sys.stdin.readline())
graph = [[] for _ in range(n_people + 1)]
for _ in range(n_edges):
    data1, data2 = map(int, sys.stdin.readline().split())
    graph[data1].append(data2)
    graph[data2]. append(data1)

visited = [-1] * (n_people + 1)
result = bfs(graph, p1, p2)

print(result)