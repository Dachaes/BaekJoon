# boj_15489 : 파스칼 삼각형
import sys

# input
start_x, start_y, n = map(int, sys.stdin.readline().split())
dp = [[], [1], [1, 1]]

for i in range(3, start_x + n):
    temp = [1]
    for j in range(i - 2):
        temp.append(dp[i - 1][j] + dp[i - 1][j + 1])
    temp.append(1)
    dp.append(temp)

sum_number, count = 0, 1
for i in range(start_x, start_x + n):
    for j in range(count):
        sum_number += dp[i][(start_y - 1) + j]
    count += 1

print(sum_number)