# BOJ_1976 : 여행 가자
import sys


# 부모를 찾는 함수
def find_parents(x):
	if x == parents[x]:
		return x

	parents[x] = find_parents(parents[x])
	return parents[x]


# 두 집합을 합치는 함수
def union(x, y):
	par_x, par_y = find_parents(x), find_parents(y)

	if par_x == par_y:
		return

	if par_x < par_y:
		parents[par_y] = par_x
	else:
		parents[par_x] = par_y


# input
n_cities = int(sys.stdin.readline())
n_travels = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n_cities)]
travels = list(map(int, sys.stdin.readline().split()))

parents = [i for i in range(n_cities + 1)]

for i in range(n_cities):
	for j in range(n_cities):
		if arr[i][j]:
			union(i + 1, j + 1)

results = set()
for travel in travels:
	results.add(find_parents(travel))

if len(results) == 1:
	print('YES')
else:
	print('NO')