# BOJ_1149 : RGB 거리
import sys
from math import sqrt
inf = int(1e9)

n = int(sys.stdin.readline())
cost = [[0], [0], [0]]
for i in range(n):
    datas = list(map(int, sys.stdin.readline().split()))
    for i in range(len(datas)):
        cost[i].append(datas[i])
cost_r, cost_g, cost_b = cost[0], cost[1], cost[2]

dp = [-1] + [inf] * n

ex_temp1, ex_temp2, ex_temp3 = 0, 0, 0
for i in range(1, n + 1):
    temp1 = min(ex_temp2 + cost_r[i], ex_temp3 + cost_r[i])
    temp2 = min(ex_temp1 + cost_g[i], ex_temp3 + cost_g[i])
    temp3 = min(ex_temp1 + cost_b[i], ex_temp2 + cost_b[i])
    dp[i] = min(temp1, temp2, temp3)
    ex_temp1, ex_temp2, ex_temp3 = temp1, temp2, temp3

print(dp[n])