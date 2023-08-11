# BOJ_1037 : 약수
import sys

n_divisors = int(sys.stdin.readline())
divisors = list(map(int, sys.stdin.readline().split()))

min_divisor = min(divisors)
max_divisor = max(divisors)

if min_divisor == max_divisor:
    print(min_divisor ** 2)
else:
    print(min_divisor * max_divisor)