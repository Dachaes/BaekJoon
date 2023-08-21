# BOJ_4963 : 섬의 개수
import sys
sys.setrecursionlimit(10 ** 6)

dx = [-1, 1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, -1, 1, -1, 1]


def dfs(arr, pos_x, pos_y):
    global x, y
    arr[pos_x][pos_y] = 0
    for p in range(8):
        pos_nx, pos_ny = pos_x + dx[p], pos_y + dy[p]
        if 0 <= pos_nx < x and 0 <= pos_ny < y and arr[pos_nx][pos_ny] == 1:
            arr = dfs(arr, pos_nx, pos_ny)

    return arr


while True:
    y, x = map(int, sys.stdin.readline().split())
    if (x, y) == (0, 0):
        break
    array = [list(map(int, sys.stdin.readline().split())) for _ in range(x)]

    result = 0
    for i in range(x):
        for j in range(y):
            if array[i][j] == 1:
                result += 1
                dfs(array, i, j)

    print(result)