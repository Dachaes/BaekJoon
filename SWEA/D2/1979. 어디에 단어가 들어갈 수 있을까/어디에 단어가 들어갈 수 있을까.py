n_tests = int(input())

for t in range(n_tests):
	N, K = map(int, input().split())
	arr = [list(map(int, input().split())) for _ in range(N)]

	result = 0
	# 1. 가로
	for i in range(N):
		blank = 0
		for j in range(N):
			# 1-1. 흰 칸을 찾는다면
			if arr[i][j] == 1:
				blank += 1
				# 흰 칸인데 그 칸이 마지막 칸이라면
				# 빈 칸 길이(blank) 가 단어 길이(K) 와 같은 지 확인한다.
				if j == N - 1 and blank == K:
					result += 1
			# 1-2. 검은 칸을 찾는다면
			elif arr[i][j] == 0:
				# 빈 칸 길이(blank) 가 단어 길이(K) 와 같은 지 확인한다.
				if blank == K:
					result += 1
				blank = 0

	# 2. 세로
	for j in range(N):
		blank = 0
		for i in range(N):
			# 2-1. 흰 칸을 찾는다면
			if arr[i][j] == 1:
				# 흰 칸인데 그 칸이 마지막 칸이라면
				# 빈 칸 길이(blank) 가 단어 길이(K) 와 같은 지 확인한다.
				blank += 1
				if i == N - 1 and blank == K:
					result += 1
			# 2-2. 검은 칸을 찾는다면
			elif arr[i][j] == 0:
				# 빈 칸 길이(blank) 가 단어 길이(K) 와 같은 지 확인한다.
				if blank == K:
					result += 1
				blank = 0

	print(f"#{t + 1}", result)