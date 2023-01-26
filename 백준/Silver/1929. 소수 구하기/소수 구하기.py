# BOJ_1929 : 소수 구하기
# 에라토스테네스의 체
M, N = map(int, input().split())
primes = [False] * 2 + [True] * (N - 1)


for i in range(2, N + 1):
    if primes[i]:
        for j in range(i, N + 1, i):
            if i != j:
                primes[j] = False

for i in range(M, N + 1):
     if primes[i]:
         print(i)