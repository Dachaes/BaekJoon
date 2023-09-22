# BOJ_17352 : 여러분의 다리가 되어 드리겠습니다!
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
n = int(sys.stdin.readline())
bridges = [list(map(int, sys.stdin.readline().split())) for _ in range(n - 2)]
parents = [i for i in range(n + 1)]

for bridge in bridges:
	island1, island2 = bridge
	union(island1, island2)

island1, island2 = None, None
for i in range(1, n + 1):
	island2 = find_parents(i)
	if island1 is None:
		island1 = island2
	elif island1 != island2:
		break

print(island1, island2)