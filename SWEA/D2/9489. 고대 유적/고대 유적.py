n_tests = int(input())

for t in range(1, n_tests + 1):
	n, m = map(int, input().split())
	array = [list(map(int, input().split())) for _ in range(n)]

	longest_length = 0								# longest_length: 가장 긴 구조물의 길이
	# 1. 가로행에서의 각각의 구조물의 길이를 구하여 longest_length 랑 비교하는 작업을 거친다.
	for i in range(n):
		length = 0									# length: 구조물의 길이
		for j in range(m):
			if array[i][j] == 1:					# 1-1. 길이를 센 적이 없는데, 구조물이 나타났을 때
				length += 1							# 구조물의 길이를 체크한다.
			else:									# 1-2. 길이를 세고있었는데, 구조물이 끝났을 때
				if length > longest_length:			# 구조물의 길이(length)를 longest_length와 비교하고,
					longest_length = length
				length = 0							# 구조물의 길이(length)를 초기화한다.

		if length > longest_length:
			longest_length = length

	# 2. 세로행에서의 각각의 구조물의 길이를 구하여
	# longest_length 랑 비교하는 작업을 거친다.
	for i in range(m):
		length = 0									# length: 구조물의 길이
		for j in range(n):
			if array[j][i] == 1:					# 2-1. 길이를 센 적이 없는데, 구조물이 나타났을 때
				length += 1							# 구조물의 길이를 체크한다.
			else:									# 2-2. 길이를 세고있었는데, 구조물이 끝났을 때
				if length > longest_length:			# 구조물의 길이(length)를 longest_length와 비교하고,
					longest_length = length
				length = 0							# 구조물의 길이(length)를 초기화한다.
		if length > longest_length:
			longest_length = length

	print(f"#{t}", longest_length)