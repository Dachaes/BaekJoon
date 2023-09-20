# parent 를 찾는 연산
def find_set(x):
	if parent[x] == x:
		return x

	parent[x] = find_set(parent[x])
	return parent[x]


# a 와 b 를 합치는 함수
def union(a, b):
	par_a = find_set(a)
	par_b = find_set(b)

	if par_a == par_b:
		return

	if par_a < par_b:
		parent[par_b] = par_a
	else:
		parent[par_a] = par_b


n_tests = int(input())

for t in range(1, n_tests + 1):
	n_students, n_requests = map(int, input().split())
	requests = list(map(int, input().split()))

	# parent: 부모 정보를 저장하는 리스트
	parent = [i for i in range(n_students + 1)]

	# requests 에 따라서 조를 합치는 (union) 과정을 한다.
	for i in range(0, n_requests * 2, 2):
		union(requests[i], requests[i + 1])

	# result: parent 의 중복을 제거하여, 몇 개의 조가 남아있는 지 확인하는 변수
	# student0 도 포함되어 있기 때문에, 길이 상으로 1 개가 많다.
	for i in range(1, n_students + 1):
		find_set(i)

	result = set(parent)
	print(f"#{t} {len(result) - 1}")