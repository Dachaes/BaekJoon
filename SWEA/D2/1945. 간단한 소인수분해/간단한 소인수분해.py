n_tests = int(input())
primes = [2, 3, 5, 7, 11]

for t in range(n_tests):
	number = int(input())
	abcde = [0, 0, 0, 0, 0]
	idx = 0
	for idx in range(5):
		prime, count = primes[idx], 0
		# 1. 주어진 숫자(number)가 소수(prime)로 나눠지지 않을 때까지
		# number 값을 바꾸면서 counting 한다.
		while number % prime == 0:
			number //= prime
			count += 1
		# 2. counting 이 끝났으면 출력할 리스트(abcde)에 저장한다.
		abcde[idx] = count

	print(f"#{t + 1}", *abcde)