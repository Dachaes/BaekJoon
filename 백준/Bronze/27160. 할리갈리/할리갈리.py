# BOJ_27160 : 할리갈리
import sys

n = int(sys.stdin.readline())

halli_galli = {}
for _ in range(n):
    data = list(sys.stdin.readline().split())
    if data[0] not in halli_galli.keys():
        halli_galli[data[0]] = int(data[1])
    else:
        halli_galli[data[0]] += int(data[1])

convert_halgal = {}
for k, v in halli_galli.items():
    convert_halgal[v] = k

if convert_halgal.get(5):
    print('YES')
else:
    print('NO')