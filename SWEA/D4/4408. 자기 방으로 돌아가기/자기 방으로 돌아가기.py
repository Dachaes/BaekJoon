n_tests = int(input())

for t in range(1, n_tests + 1):
	# n_students: 학생의 수
	# rooms: [현재 방, 돌아가야 할 방] 들이 저장되어있는 리스트
	n_students = int(input())
	rooms = [list(map(lambda x: (int(x) - 1) // 2, input().split())) for _ in range(n_students)]

	corridor = [0] * 200

	for room in rooms:
		room1, room2 = room[0], room[1]
		if room1 < room2:
			for j in range(room1, room2 + 1):
				corridor[j] += 1
		else:
			for j in range(room2, room1 + 1):
				corridor[j] += 1

	print(f"#{t}", max(corridor))
