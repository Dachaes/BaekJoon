# boj_11727 : 2xn 타일링 2
import sys

# input
N = int(sys.stdin.readline())
dp = [-1, 1, 3]

for i in range(3, N + 1):
    dp.append((dp[i - 1] + dp[i - 2] * 2) % 10007)

print(dp[N])