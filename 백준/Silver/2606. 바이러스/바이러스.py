# BOJ_2606 : 바이러스
import sys


def dfs(g, start):
    global visited, count
    stack = [start]
    visited[start] = True
    while stack:
        pos = stack[-1]
        for n_pos in graph[pos]:
            if not visited[n_pos]:
                stack.append(n_pos)
                visited[n_pos] = True
                count += 1
                break
        else:
            stack.pop()


n_computers = int(sys.stdin.readline())
n_edges = int(sys.stdin.readline())
graph = [[] for _ in range(n_computers + 1)]
for _ in range(n_edges):
    data1, data2 = map(int, sys.stdin.readline().split())
    graph[data1].append(data2)
    graph[data2].append(data1)

visited = [False] * (n_computers + 1)
count = 0

dfs(graph, 1)

print(count)