# BOJ_2669 : 직사각형 네개의 합집합의 면적 구하기
import sys

rectangles = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
paper = [[0] * 101 for _ in range(101)]

for rectangle in rectangles:
    start_x, start_y, end_x, end_y = rectangle[:]
    for i in range(start_x, end_x):
        for j in range(start_y, end_y):
            paper[i][j] = 1

area = 0
for i in range(101):
    area += paper[i].count(1)
print(area)