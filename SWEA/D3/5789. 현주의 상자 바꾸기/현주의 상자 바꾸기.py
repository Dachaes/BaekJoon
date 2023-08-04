n_tests = int(input())

for t in range(n_tests):
	n_boxes, n_checks = map(int, input().split())
	# checks: 체크하는 입력 리스트, boxes: 박스의 번호 리스트
	checks = [list(map(int, input().split())) for _ in range(n_checks)]
	boxes = [0] * (n_boxes + 1)

	check_number = 1
	for check in checks:
		start, end = check[0], check[1]
		for idx in range(start, end + 1):
			boxes[idx] = check_number
		check_number += 1

	print(f"#{t + 1}", *boxes[1:])