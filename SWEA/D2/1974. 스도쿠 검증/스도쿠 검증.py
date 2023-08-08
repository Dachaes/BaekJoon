from copy import deepcopy

n_tests = int(input())


def my_count(datas, key):
	count = 0
	for data in datas:
		if data == key:
			count += 1
	return count


for t in range(n_tests):
	# numbers: 스토쿠 행렬
	# numbers_T: 스토쿠 행렬의 전치 행렬
	numbers = [list(map(int, input().split())) for _ in range(9)]
	numbers_T = deepcopy(numbers)
	for i in range(9):
		for j in range(9):
			if i < j:
				numbers_T[i][j], numbers_T[j][i] = numbers_T[j][i], numbers_T[i][j]

	result = 1
	# 가로 행을 매번 체크할 때마다 체크 리스트를 만들어서
	# 1부터 9까지 각각 1개씩 있는지 확인한다.
	for number in numbers:
		cnt_list = [0] * 9
		for num in number:
			cnt_list[num - 1] += 1
		if my_count(cnt_list, 1) != 9:
			result = 0

	# 세로 열을 매번 체크할 때마다 체크 리스트를 만들어서
	# 1부터 9까지 각각 1개씩 있는지 확인한다.
	if result:
		for number in numbers_T:
			cnt_list = [0] * 9
			for num in number:
				cnt_list[num - 1] += 1
			if my_count(cnt_list, 1) != 9:
				result = 0

	# 칸 별로 매번 체크할 때마다 체크 리스트를 만들어서
	# 1부터 9까지 각각 1개씩 있는지 확인한다.
	for i in range(0, 7, 3):
		for j in range(0, 7, 3):
			cnt_list = [0] * 9
			for k in range(3):
				for l in range(3):
					cnt_list[numbers[i+k][j+l] - 1] += 1
			if my_count(cnt_list, 1) != 9:
				result = 0

	print(f"#{t + 1}", result)