# BOJ_11726 : 2xn 타일링
import sys

while True:
    try:
        n = int(sys.stdin.readline())
        dp = [1, 1, 3] + [-1] * (n - 2)
        for i in range(3, n + 1):
            dp[i] = (2 * dp[i - 2]) + dp[i - 1]
    
        print(dp[n])
    
    except:
        break