# BOJ_17404 : RGB 거리 2
import sys
INF = int(1e9)

n = int(sys.stdin.readline())
cost = [[0], [0], [0]]
for i in range(n):
    datas = list(map(int, sys.stdin.readline().split()))
    for i in range(len(datas)):
        cost[i].append(datas[i])
cost_r, cost_g, cost_b = cost[0], cost[1], cost[2]


def rgb_cost(start):
    dp = [-1] + [INF] * 2 * n
    copy_cost_r = cost_r[:]
    copy_cost_g = cost_g[:]
    copy_cost_b = cost_b[:]

    cost1 = cost[start][1]
    if start == 0:
        copy_cost_g[1], copy_cost_b[1] = cost1, cost1
        copy_cost_r[2], copy_cost_r[-1] = INF, INF
    elif start == 1:
        copy_cost_r[1], copy_cost_b[1] = cost1, cost1
        copy_cost_g[2], copy_cost_g[-1] = INF, INF
    else:
        copy_cost_r[1], copy_cost_g[1] = cost1, cost1
        copy_cost_b[2], copy_cost_b[-1] = INF, INF

    ex_temp1, ex_temp2, ex_temp3 = 0, 0, 0
    for i in range(1, n + 1):
        temp1 = min(ex_temp2 + copy_cost_r[i], ex_temp3 + copy_cost_r[i])
        temp2 = min(ex_temp1 + copy_cost_g[i], ex_temp3 + copy_cost_g[i])
        temp3 = min(ex_temp1 + copy_cost_b[i], ex_temp2 + copy_cost_b[i])
        dp[i] = min(temp1, temp2, temp3)
        ex_temp1, ex_temp2, ex_temp3 = temp1, temp2, temp3
    
    return dp[n]


answers = []
for color in range(3):
    answers.append(rgb_cost(color))

print(min(answers))