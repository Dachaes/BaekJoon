n_tests = int(input())

for t in range(1, n_tests + 1):
	days = int(input())
	prices = list(map(int, input().split()))

	sum_profit = 0
	while prices:
		# 1. 최대 판매가와 그날이 언제인지 구한다.
		selling_day, selling_price = 0, 0
		for day, price in enumerate(prices):
			if price >= selling_price:
				selling_day = day
				selling_price = price

		# 2. 최대 판매가로 팔 수 있는 날의 전날들(과거) 계산을 완료한다.
		for purchased_day in range(selling_day, -1, -1):
			purchased_price = prices.pop(purchased_day)
			# 3. 차익을 계산한다.
			profit = selling_price - purchased_price
			if profit > 0:
				sum_profit += profit

	print(f"#{t}", sum_profit)
