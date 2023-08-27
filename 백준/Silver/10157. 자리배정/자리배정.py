# BOJ_10157 : 자리 배정
import sys

# 우, 하, 좌, 상
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
direction = -1

# input
x, y = map(int, sys.stdin.readline().split())
place = [[0] * y for _ in range(x)]
me = int(sys.stdin.readline())

pos_x, pos_y, count = 0, 0, 1
if me > x * y:
    print(0)

else:
    while True:
        if place[pos_x][pos_y] == 0:
            place[pos_x][pos_y] = count
            if count == me:
                print(pos_x + 1, pos_y + 1)
                break
            count += 1

            npos_x, npos_y = pos_x + dx[direction], pos_y + dy[direction]
            if 0 <= npos_x < x and 0 <= npos_y < y and not place[npos_x][npos_y]:
                pos_x, pos_y = npos_x, npos_y
            else:
                direction = (direction + 1) % 4
                pos_x, pos_y = pos_x + dx[direction], pos_y + dy[direction]