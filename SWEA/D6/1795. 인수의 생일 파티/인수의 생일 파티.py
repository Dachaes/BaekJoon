import heapq
INF = int(1e9)


def dijkstra(s, graphs, distances):
	# 초기 값 설정
	pq = []
	heapq.heappush(pq, [0, s])
	distances[s] = 0

	# 이후 값 설정
	while pq:
		# 1. 현재 값 가져오기
		dist, now_v = heapq.heappop(pq)

		# 이미 저장된 누적 거리 값보다 지금 비교하려고 가져 온 누적 거리 값이 크면, 볼 필요가 없다. (가지치기)
		if distances[now_v] < dist:
			continue

		# 2. 다음 값 가져오기
		for nexts in graphs[now_v]:
			next_dist = dist + nexts[0]
			next_v = nexts[1]

			if next_dist <= distances[next_v]:
				distances[next_v] = next_dist
				heapq.heappush(pq, [next_dist, next_v])


n_tests = int(input())

for t in range(1, n_tests + 1):
	num_vertexs, num_edges, start = map(int, input().split())
	graphs_go = [[] for _ in range(num_vertexs + 1)]
	graphs_back = [[] for _ in range(num_vertexs + 1)]
	for i in range(num_edges):
		x, y, d = list(map(int, input().split()))
		# x -> y 가는데, d 만큼 걸린다.
		graphs_go[y].append([d, x])
		graphs_back[x].append([d, y])

	# 목표 지점 까지 갈 때
	distances1 = [-1] + [INF] * num_vertexs
	dijkstra(start, graphs_go, distances1)
	# 목표 지점에서 돌아올 때
	distances2 = [-1] + [INF] * num_vertexs
	dijkstra(start, graphs_back, distances2)

	distances = [x + y for x, y in zip(distances1, distances2)]

	result = max(distances)
	print(f"#{t} {result}")