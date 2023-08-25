n_tests = int(input())

for t in range(1, n_tests + 1):
	# n 명의 사람이 자격을 얻었다., m 초의 시간을 들이면 k 개의 붕어빵을 만들 수 있다.
	n, m, k = map(int, input().split())
	# people: 사람이 언제 도착하는지를 초 단위로 나타낸 리스트
	people = list(map(int, input().split()))
	people.sort()

	time, bread = 0, 0

	notation = 'Possible'
	for person in people:
		while time < person:
			time += m
			bread += k
			if time > person:
				time -= m
				bread -= k
				break

		if bread == 0:
			notation = 'Impossible'
			break
		else:
			bread -= 1

	print(f"#{t}", notation)