# BOJ_16398 : 행성 연결
import sys
import heapq


def find_set(x):
	if parents[x] == x:
		return x

	parents[x] = find_set(parents[x])
	return parents[x]


def union(x, y):
	par_x, par_y = find_set(x), find_set(y)

	if par_x == par_y:
		return

	if par_x < par_y:
		parents[par_y] = par_x
	else:
		parents[par_x] = par_y


def kruskal():
	cnt, res = 0, 0
	while pq:
		w, s, e = heapq.heappop(pq)
		if find_set(s) != find_set(e):
			union(s, e)
			cnt += 1
			res += w
		if cnt == num_vertexs - 1:
			break

	return res


# input
num_vertexs = int(sys.stdin.readline())
pq = []
for i in range(num_vertexs):
	weights = list(map(int, sys.stdin.readline().split()))
	for j in range(num_vertexs):
		heapq.heappush(pq, [weights[j], i + 1, j + 1])

parents = [i for i in range(num_vertexs + 1)]

result = kruskal()
print(result)