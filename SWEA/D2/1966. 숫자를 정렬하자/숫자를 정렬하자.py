n_tests = int(input())

for k in range(n_tests):
	n_numbers = int(input())
	numbers = list(map(int, input().split()))

	for i in range(n_numbers - 1, 0, -1):
		for j in range(i):
			if numbers[j] > numbers[j + 1]:
				numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]

	print(f"#{k + 1}", *numbers)