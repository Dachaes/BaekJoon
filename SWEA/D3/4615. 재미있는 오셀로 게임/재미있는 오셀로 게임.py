dx = [-1, 1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, 1, -1, 1, -1]


def othello(pos_x, pos_y, me):
	global board
	change_color = [(pos_x, pos_y)]
	you = 1
	if me == 1:
		you = 2

	for p in range(8):
		npos_x, npos_y = pos_x + dx[p], pos_y + dy[p]
		can_change = False
		temp = []
		while 0 <= npos_x < n_board and 0 <= npos_y < n_board:
			if board[npos_x][npos_y] == 0:
				break
			elif board[npos_x][npos_y] == you:
				temp.append((npos_x, npos_y))
			elif board[npos_x][npos_y] == me:
				can_change = True
				break

			npos_x, npos_y = npos_x + dx[p], npos_y + dy[p]

		if can_change:
			change_color.extend(temp)

	for pos_x, pos_y in change_color:
		board[pos_x][pos_y] = me


n_tests = int(input())

for t in range(1, n_tests + 1):
	n_board, n_rocks = map(int, input().split())
	board = [[0] * n_board for _ in range(n_board)]

	board[n_board // 2 - 1][n_board // 2 - 1], board[n_board // 2][n_board // 2] = 2, 2
	board[n_board // 2][n_board // 2 - 1], board[n_board // 2 - 1][n_board // 2] = 1, 1

	for _ in range(n_rocks):
		x, y, color = map(int, input().split())
		othello(x - 1, y - 1, color)

	black_points, white_points = 0, 0

	for line in board:
		black_points += line.count(1)
		white_points += line.count(2)

	print(f"#{t}", black_points, white_points)