# BOJ_1699 : 제곱수의 합
import sys
from math import sqrt
sys.setrecursionlimit(100000)

x = int(sys.stdin.readline())
numbers = [(num ** 2) for num in range(1, int(sqrt(x)) + 1)]

INF = int(1e9)
dp = [0] + [INF] * x
for i in range(1, x + 1):
    for number in numbers:
        if number <= i:
            dp[i] = min(dp[i], dp[i - number] + 1)
         
print(dp[x])