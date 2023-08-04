di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]

n_tests = int(input())

for t in range(n_tests):
	N, M = map(int, input().split())
	arr = [list(map(int, input().split())) for _ in range(N)]
	max_pollen = 0
	for i in range(N):
		for j in range(M):
			# 1. pollen 에 기준 점이 될 풍선의 꽃가루를 저장한다.
			center_balloon, pollen = arr[i][j], arr[i][j]
			# 2. pollen 의 값만큼 상하좌우의 풍선을 탐색한다.
			for p in range(4):
				ni, nj = i, j		# 기준점 위치 저장
				for _ in range(center_balloon):
					ni, nj = ni + di[p], nj + dj[p]
					if 0 <= ni < N and 0 <= nj < M:
						pollen += arr[ni][nj]
					else:
						break
			# 3. 탐색을 완료하고, max 값을 갱신한다.
			max_pollen = max(max_pollen, pollen)

	print(f"#{t + 1}", max_pollen)