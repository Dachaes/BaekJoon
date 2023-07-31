# BOJ_14425 : 문자열 집합
import sys

n, m = map(int, sys.stdin.readline().split())
set1, list2 = set(), []

for _ in range(n):
    set1.add(sys.stdin.readline().rstrip())

for _ in range(m):
    list2.append(sys.stdin.readline().rstrip())

count = 0
for word in list2:
    if word in set1:
        count += 1

print(count)