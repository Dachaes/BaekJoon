# BOJ_7576 : 토마토
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(arr, input_pos):
    global x, y
    stack = [input_pos]
    cnt = -1
    while stack:
        pos_list = stack.pop(0)
        cnt += 1
        npos_list = []
        for pos in pos_list:
            pos_x, pos_y = pos[0], pos[1]
            for p in range(4):
                npos_x, npos_y = pos_x + dx[p], pos_y + dy[p]
                if 0 <= npos_x < x and 0 <= npos_y < y and arr[npos_x][npos_y] == 0:
                    arr[npos_x][npos_y] = 1
                    npos_list.append([npos_x, npos_y])
        if npos_list:
            stack.append(npos_list)

    return cnt

# input
y, x = map(int, sys.stdin.readline().split())
array = [list(map(int, sys.stdin.readline().split())) for _ in range(x)]

position = []
for i in range(x):
    for j in range(y):
        if array[i][j] == 1:
            position.append([i, j])

count = bfs(array, position)

is_possible = True
for a in array:
    if a.count(0):
        is_possible = False

if is_possible:
    print(count)
else:
    print(-1)
