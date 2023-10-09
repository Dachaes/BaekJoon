# BOJ_14503 : 로봇 청소기
import sys

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def dfs_14503(x, y, d, cnt):
    global n, m

    if not arr[x][y]:
        arr[x][y] = 2
        cnt += 1

    for _ in range(4):
        d = (d - 1) % 4
        nx, ny = x + dx[d], y + dy[d]
        if 0 <= nx < n and 0 <= ny < m:
            if not arr[nx][ny]:
                cnt = dfs_14503(nx, ny, d, cnt)
                break
    else:
        nx, ny = x - dx[d], y - dy[d]
        if 0 <= nx < n and 0 <= ny < m:
            if arr[nx][ny] != 1:
                cnt = dfs_14503(nx, ny, d, cnt)

    return cnt


n, m = map(int, sys.stdin.readline().split())
start_x, start_y, direction = map(int, sys.stdin.readline().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

result = dfs_14503(start_x, start_y, direction, 0)

print(result)