# BOJ_11047 : 동전 0
import sys

# N: 동전의 종류, K: 동전 가치의 합
N, K = map(int, sys.stdin.readline().split())
coins = []
for _ in range(N):
    coins.append(int(sys.stdin.readline()))
coins.sort(reverse=True)

count = 0
while K != 0:
    for coin in coins:
        if K >= coin:
            count += K // coin
            K %= coin

print(count)