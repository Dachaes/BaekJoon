# boj_11123 : 양 한마리... 양 두마리...
import sys
sys.setrecursionlimit(10**6)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(arr, pos_x, pos_y):
    global x, y
    arr[pos_x][pos_y] = '.'
    for p in range(4):
        pos_nx, pos_ny = pos_x + dx[p], pos_y + dy[p]
        if 0 <= pos_nx < x and 0 <= pos_ny < y and arr[pos_nx][pos_ny] == '#':
            arr = dfs(arr, pos_nx, pos_ny)

    return arr

# input
n_tests = int(sys.stdin.readline())

for t in range(1, n_tests + 1):
    x, y = map(int, sys.stdin.readline().split())
    array = []
    for _ in range(x):
        array.append(list(sys.stdin.readline().strip()))

    count = 0
    for i in range(x):
        for j in range(y):
            if array[i][j] == '#':
                array = dfs(array, i, j)
                count += 1

    print(count)