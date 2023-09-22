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


n_tests = int(input())

for t in range(1, n_tests + 1):
	num_vertexs, num_edges = map(int, input().split())
	# graphs: [v1, v2], v1과 v2 는 서로 알고 있다.
	graphs = [list(map(int, input().split())) for _ in range(num_edges)]
	# parents: 부모 정보를 저장하는 리스트 (같은 집합 내에 있는지 확인할 수 있다.)
	parents = [i for i in range(num_vertexs + 1)]

	# graphs 를 돌면서, 서로 알고 있는 v1 과 v2 를 같은 집합 취급한다.
	for graph in graphs:
		v1, v2 = graph
		union(v1, v2)

	# 각 vertexs 의 부모값을 갱신한다.
	for i in range(1, num_vertexs + 1):
		find_parents(i)

	# result: parents 에 집합의 대표자만 저장되어있으므로 부모의 수와 같다.
	result = len(set(parents)) - 1

	print(f"#{t} {result}")
