def convert2_to_10(number, x):
	result = ''
	result = number[:x] + str(int(number[x]) ^ 1) + number[x + 1:]

	return int(result, 2)


def convert3_to_10(number, x):
	results = []
	result = number[:x] + str((int(number[x]) + 1) % 3) + number[x + 1:]
	results.append(int(result, 3))

	result = number[:x] + str((int(number[x]) + 2) % 3) + number[x + 1:]
	results.append(int(result, 3))

	return results


n_tests = int(input())

for t in range(1, n_tests + 1):
	number2 = input()
	number3 = input()

	is_done = False
	for i in range(len(number2)):
		number10_1 = convert2_to_10(number2, i)
		for j in range(len(number3)):
			number10_2s = convert3_to_10(number3, j)
			for number10_2 in number10_2s:
				if number10_1 == number10_2:
					is_done = True
					print(f"#{t}", number10_1)
					break
			if is_done:
				break
		if is_done:
			break
