# BOJ_1463 : 1로 만들기
import sys

n = int(sys.stdin.readline())

dp = [-1] + [0] * n

for i in range(1, n + 1):
    if i == 1:
        dp[i] = 0
    elif i % 3 == 0 and i % 2 == 0:
        dp[i] = min(dp[i // 3] + 1, dp[i // 2] + 1, dp[i - 1] + 1)
    elif i % 3 == 0:
        dp[i] = min(dp[i // 3] + 1, dp[i - 1] + 1)
    elif i % 2 == 0:
        dp[i] = min(dp[i // 2] + 1, dp[i - 1] + 1)
    else:
        dp[i] = dp[i - 1] + 1

print(dp[n])