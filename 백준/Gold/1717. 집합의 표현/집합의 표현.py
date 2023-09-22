# BOJ_1717 : 집합의 표현
import sys
sys.setrecursionlimit(10**6)


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
num_numbers, num_operations = map(int, sys.stdin.readline().split())
operations = [list(map(int, sys.stdin.readline().split())) for _ in range(num_operations)]

parents = [i for i in range(num_numbers + 1)]

for operation in operations:
	op, n1, n2 = operation
	if op == 0:
		union(n1, n2)
	else:
		if find_parents(n1) == find_parents(n2):
			print('YES')
		else:
			print('NO')
