# boj_1012 : 유기농 배추
import sys
sys.setrecursionlimit(10**6)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(arr, pos_x, pos_y):
    global x, y
    arr[pos_x][pos_y] = 0
    for p in range(4):
        pos_nx, pos_ny = pos_x + dx[p], pos_y + dy[p]
        if 0 <= pos_nx < x and 0 <= pos_ny < y and arr[pos_nx][pos_ny]:
            arr = dfs(arr, pos_nx, pos_ny)

    return arr

# input
n_tests = int(sys.stdin.readline())

for t in range(1, n_tests + 1):
    x, y, k = map(int, sys.stdin.readline().split())
    array = [[0] * y for _ in range(x)]
    for _ in range(k):
        i, j = map(int, sys.stdin.readline().split())
        array[i][j] = 1

    count = 0
    for i in range(x):
        for j in range(y):
            if array[i][j] == 1:
                array = dfs(array, i, j)
                count += 1
    print(count)