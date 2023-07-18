# BOJ_1926 : 그림
import sys
sys.setrecursionlimit(10 ** 6)

# Input
n, m = map(int, input().split())
paper = []
for _ in range(n):
    paper.append(list(map(int, input().split())))

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def dfs(x, y, size):
    paper[x][y] = -1
    size += 1
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if paper[nx][ny] == 1:
                size = dfs(nx, ny, size)
    return size


num_pictures = 0
max_size = 0
for i in range(n):
    for j in range(m):
        if paper[i][j] == 1:
            pic_size = 0
            num_pictures += 1
            max_size = max(dfs(i, j, pic_size), max_size)

print(num_pictures)
print(max_size)