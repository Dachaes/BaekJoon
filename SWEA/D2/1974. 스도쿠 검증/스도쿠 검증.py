from copy import deepcopy

n_tests = int(input())

for t in range(n_tests):
	numbers = [list(map(int, input().split())) for _ in range(9)]
	numbers_T = deepcopy(numbers)
	for i in range(9):
		for j in range(9):
			if i < j:
				numbers_T[i][j], numbers_T[j][i] = numbers_T[j][i], numbers_T[i][j]

	result = 1
	# 가로
	for number in numbers:
		cnt_list = [0] * 9
		for num in number:
			cnt_list[num - 1] += 1
		if cnt_list.count(1) != 9:
			result = 0
	# 세로
	if result:
		for number in numbers_T:
			cnt_list = [0] * 9
			for num in number:
				cnt_list[num - 1] += 1
			if cnt_list.count(1) != 9:
				result = 0
	# 칸 별로
	for i in range(0, 7, 3):
		for j in range(0, 7, 3):
			cnt_list = [0] * 9
			for k in range(3):
				for l in range(3):
					cnt_list[numbers[i+k][j+l] - 1] += 1
			if cnt_list.count(1) != 9:
				result = 0

	print(f"#{t + 1}", result)