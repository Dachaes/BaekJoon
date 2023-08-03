dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

n_tests = int(input())

for t in range(n_tests):
	N = int(input())
	arr = [[0] * N for _ in range(N)]
	numbers = [num for num in range(1, N * N + 1)]

	x, y, direction = 0, 0, 0
	for number in numbers:
		arr[x][y] = number

		nx, ny = x + dx[direction], y + dy[direction]
		if (not (0 <= nx < N and 0 <= ny < N)) or (arr[nx][ny] != 0):
			direction = (direction + 1) % 4
			nx, ny = x + dx[direction], y + dy[direction]

		x, y = nx, ny

	print(f"#{t + 1}")
	for a in arr:
		print(*a)
