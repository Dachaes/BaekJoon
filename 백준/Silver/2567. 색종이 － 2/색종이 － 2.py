# BOJ_2567 : 색종이 2
import sys

n = int(sys.stdin.readline())
start_points = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

paper = [[0] * 100 for _ in range(100)]

for start_point in start_points:
    x, y = start_point
    for i in range(y, y + 10):
        for j in range(x, x + 10):
            paper[i][j] = 1

len_y = 0
pre_point = None
for line in paper:
    for idx, point in enumerate(line):
        if idx == 0:
            pre_point = point
            if point:
                len_y += 1
        elif pre_point != point:
            len_y += 1
            pre_point = point
        elif idx == 99 and point:
            len_y += 1

idx, len_x = 0, 0
pre_point = None
for i in range(100):
    for j in range(100):
        idx, point = j, paper[j][i]
        if idx == 0:
            pre_point = point
            if point:
                len_y += 1
        elif pre_point != point:
            len_y += 1
            pre_point = point
        elif idx == 99 and point:
            len_y += 1

print(len_y + len_x)