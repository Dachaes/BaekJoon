# BOJ_1922 : 네트워크 연결
import sys
import heapq


def find_set(x):
	if parents[x] == x:
		return x

	parents[x] = find_set(parents[x])
	return parents[x]


def union(x, y):
	pra_x, par_y = find_set(x), find_set(y)

	if pra_x == par_y:
		return

	if pra_x < par_y:
		parents[par_y] = pra_x
	else:
		parents[pra_x] = par_y


def kruskal():
	cnt, res = 0, 0
	while pq:
		w, s, e = heapq.heappop(pq)
		if find_set(s) != find_set(e):
			union(s, e)
			cnt += 1
			res += w
		if cnt == num_edges:
			break

	return res


# input
num_vertexs = int(sys.stdin.readline())
num_edges = int(sys.stdin.readline())
pq = []
for _ in range(num_edges):
	start, end, weight = map(int, sys.stdin.readline().split())
	heapq.heappush(pq, [weight, start, end])

parents = [i for i in range(num_vertexs + 1)]

result = kruskal()
print(result)