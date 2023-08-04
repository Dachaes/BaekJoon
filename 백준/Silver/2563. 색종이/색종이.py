# BOJ_2563 : 색종이
import sys

n_blacks = int(input())
blacks = [list(map(int, sys.stdin.readline().split())) for _ in range(n_blacks)]

paper = [[0] * 100 for _ in range(100)]

for black in blacks:
    for i in range(black[0], black[0] + 10):
        for j in range(black[1], black[1] + 10):
            paper[i][j] = 1

area = 0
for i in range(100):
    area += paper[i].count(1)
print(area)