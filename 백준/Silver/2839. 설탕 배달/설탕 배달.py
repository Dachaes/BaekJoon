# BOJ_2839 : 설탕 배달
import sys
INF = int(1e9)
n = int(sys.stdin.readline())

dp = [-1] * 3 + [-1] * (n - 2)

for i in range(3, n + 1):
    if i == 3:
        dp[i] = 1
    elif i == 5:
        dp[i] = 1
    else:
        dp[i], temp1, temp2 = INF, None, None

        if dp[i - 3] != -1:
            temp1 = dp[i - 3] + 1
        if dp[i - 5] != -1:
            temp2 = dp[i - 5] + 1

        if temp1:
            dp[i] = min(temp1, dp[i])
        if temp2:
            dp[i] = min(temp2, dp[i])

        # 값이 아직도 바뀌지 않았다면
        if dp[i] == INF:
            dp[i] = -1

print(dp[-1])