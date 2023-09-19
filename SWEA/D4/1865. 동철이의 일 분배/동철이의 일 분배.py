def backtracking(employee, success_rate):
	global max_success_rate

	# 종료 조건
	if employee == n:
		max_success_rate = max(max_success_rate, success_rate)
		return

	# 가지치기
	if max_success_rate >= success_rate:
		return

	for i in range(n):
		if not done[i]:
			done[i] = True
			backtracking(employee + 1, success_rate * arr[employee][i] / 100)

			done[i] = False


n_tests = int(input())

for t in range(1, n_tests + 1):
	n = int(input())
	arr = [list(map(int, input().split())) for _ in range(n)]

	# done: 일을 했는지 안했는지 체크할 리스트
	done = [False] * n
	# max_success_rate: 성공 확률의 최대값
	max_success_rate = 0

	backtracking(0, 100)

	print(f"#{t} {max_success_rate:6f}")