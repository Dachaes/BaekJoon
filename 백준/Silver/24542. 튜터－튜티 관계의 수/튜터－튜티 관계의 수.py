# BOJ_24542 : 튜터-튜티 관계의 수
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
num_vertexs, num_edges = map(int, sys.stdin.readline().split())
graphs = [list(map(int, sys.stdin.readline().split())) for _ in range(num_edges)]

parents = [i for i in range(num_vertexs + 1)]
counts = [0 for i in range(num_vertexs + 1)]

# graphs 를 돌면서, 서로 알고 있는 v1 과 v2 를 같은 집합 취급한다.
for graph in graphs:
	v1, v2 = graph
	union(v1, v2)

# 각 vertexs 의 부모값을 갱신한다.
for i in range(1, num_vertexs + 1):
	count = find_parents(i)
	counts[count] += 1

result = 1
for i in range(1, num_vertexs + 1):
	count = counts[i]
	if count:
		result = result * count % 1000000007

print(result)
