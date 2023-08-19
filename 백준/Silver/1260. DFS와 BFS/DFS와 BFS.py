# boj_1260 : DFS 와 BFS
import sys


def dfs(s):
    result = [s]

    visited = [False] * (n_nodes + 1)
    stack = [s]
    visited[s] = True
    while stack:
        pos = stack[-1]
        for n_pos in graphs[pos]:
            if not visited[n_pos]:
                stack.append(n_pos)
                visited[n_pos] = True
                result.append(n_pos)
                break
        else:
            stack.pop()

    return result

def bfs(s):
    result = [s]

    visited = [False] * (n_nodes + 1)
    queue = [s]
    visited[s] = True
    while queue:
        pos = queue.pop(0)
        for n_pos in graphs[pos]:
            if not visited[n_pos]:
                queue.append(n_pos)
                visited[n_pos] = True
                result.append(n_pos)

    return result


n_nodes, n_edges, start = map(int, sys.stdin.readline().split())
graphs = [[] for _ in range(n_nodes + 1)]
for _ in range(n_edges):
    data1, data2 = map(int, sys.stdin.readline().split())
    graphs[data1].append(data2)
    graphs[data2].append(data1)
for graph in graphs:
    graph.sort()

res_dfs = dfs(start)
res_bfs = bfs(start)

print(*res_dfs)
print(*res_bfs)