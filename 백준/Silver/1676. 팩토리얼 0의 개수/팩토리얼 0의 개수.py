# BOJ_1676 : 팩토리얼 0 의 개수
import sys

n = int(sys.stdin.readline())

fact_n = 1
for m in range(n, 0, -1):
    fact_n *= m

result = 0
while True:
    if not fact_n % 10:
        fact_n //= 10
        result += 1
    else:
        break

print(result)