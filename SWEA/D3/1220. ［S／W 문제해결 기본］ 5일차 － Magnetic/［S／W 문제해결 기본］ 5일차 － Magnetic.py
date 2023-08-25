n_tests = 10

for t in range(1, n_tests + 1):
	# len_table: 정사각형 테이블의 한 변의 길이, table: 입력 받은 table 정보
	len_table = int(input())
	table = [list(map(int, input().split())) for _ in range(len_table)]
	while True:
		# is_changed: 테이블의 자성체 위치를 한 번이라도 바꿨다면 True, 변함이 없었다면 False
		is_changed = False
		for i in range(100):
			for j in range(100):
				# magnetic: 1 -> N극(아래로 감), 2 -> S극(위로 감)
				magnetic = table[i][j]
				# 1. 자성체가 N 극이면 아래로 내려간다.
				if magnetic == 1:
					ni, nj = i + 1, j
					if ni < 100 and not table[ni][nj]:
						table[i][j] = 0
						table[ni][nj] = 1
						is_changed = True
					elif ni >= 100:
						table[i][j] = 0
						is_changed = True
				# 2. 자성체가 S 극이면 위로 올라간다.
				elif magnetic == 2:
					ni, nj = i - 1, j
					if 0 <= ni and not table[ni][nj]:
						table[i][j] = 0
						table[ni][nj] = 2
						is_changed = True
					elif ni < 0:
						table[i][j] = 0
						is_changed = True
		# 종료 조건: 테이블의 자성체 위치가 변함이 없으면, while 문을 끝낸다.
		if not is_changed:
			break

	# table 을 세로로 한 줄씩 탐색하면서 0 에서 1 or 2 로 바뀌는 횟수가 몇 번인지 counting 한다.
	count = 0
	for i in range(100):
		for j in range(1, 100):
			if [table[j - 1][i], table[j][i]] == [1, 2]:
				count += 1

	print(f"#{t}", count)