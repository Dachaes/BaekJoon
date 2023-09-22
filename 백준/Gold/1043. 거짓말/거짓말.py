# BOJ_1043 : 거짓말
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
num_people, num_parties = map(int, sys.stdin.readline().split())
who_knows_the_truth = list(sys.stdin.readline().split())
parties = [list(map(int, sys.stdin.readline().split())) for _ in range(num_parties)]

parents = [i for i in range(num_people + 1)]

result = num_parties
num_truth = int(who_knows_the_truth[0])
people_who_knows_the_truth = set(map(int, who_knows_the_truth[1:]))

if num_truth:
	# 파티에 참석한 사람들의 부모 통일하기
	for party in parties:
		num_party = party[0]
		party = party[1:]
		for i in range(0, num_party - 1):
			union(party[i], party[i + 1])

	# 부모값 모두 갱신
	for i in range(1, num_people + 1):
		parent = find_parents(i)

	# 진실을 아는 사람들의 부모값을 추가
	for person in list(people_who_knows_the_truth):
		people_who_knows_the_truth.add(find_parents(person))

	# 진실을 아는 사람들의 부모값과 같으면, 진실을 아는 사람에 추가
	for i in range(1, num_people + 1):
		parent = find_parents(i)
		if parent in people_who_knows_the_truth:
			people_who_knows_the_truth.add(i)

	# 파티 안에서 거짓말을 할 수 있는지 확인
	for party in parties:
		for person in people_who_knows_the_truth:
			if person in party[1:]:
				result -= 1
				break

print(result)