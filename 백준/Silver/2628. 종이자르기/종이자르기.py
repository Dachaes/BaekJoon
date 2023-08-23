# BOJ_2628 : 종이 자르기
import sys

y, x = map(int, sys.stdin.readline().split())
n = int(sys.stdin.readline())
cutting1, cutting2 = [0, x], [0, y]
for _ in range(n):
    data_type, data = map(int, sys.stdin.readline().split())
    if not data_type:
        cutting1.append(data)
    else:
        cutting2.append(data)

cutting1.sort()
cutting2.sort()

length1 = []
for i in range(1, len(cutting1)):
    length1.append(cutting1[i] - cutting1[i - 1])
length2 = []
for i in range(1, len(cutting2)):
    length2.append(cutting2[i] - cutting2[i - 1])

max_rectangle = 0
for i in range(len(length1)):
    for j in range(len(length2)):
        max_rectangle = max(max_rectangle, length1[i] * length2[j])

print(max_rectangle)