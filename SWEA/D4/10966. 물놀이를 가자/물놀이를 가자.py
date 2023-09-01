from collections import deque
 
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
 
 
def bfs():
    deq = deque([])
    visited = [[-1] * m for _ in range(n)]
 
    for i in range(n):
        for j in range(m):
            if sea[i][j] == 'W':
                visited[i][j] = 0
                deq.append([i, j])
 
    while deq:
        x, y = deq.popleft()
        for p in range(4):
            nx, ny = x + dx[p], y + dy[p]
            if 0 <= nx < n and 0 <= ny < m and sea[nx][ny] == 'L':
                if visited[nx][ny] == -1:
                    visited[nx][ny] = visited[x][y] + 1
                    deq.append([nx, ny])
 
    res = 0
    for v in visited:
        res += sum(v)
 
    return res
 
n_tests = int(input())
 
for t in range(1, n_tests + 1):
    n, m = map(int, input().split())
    sea = [input() for _ in range(n)]
 
    result = bfs()
 
    print(f"#{t}", result)