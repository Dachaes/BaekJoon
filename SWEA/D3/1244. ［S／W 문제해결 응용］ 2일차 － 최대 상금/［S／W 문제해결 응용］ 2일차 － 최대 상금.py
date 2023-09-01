def backtracking(k):
	global answer, exchange_counts

	# 종료 조건: 교환 횟수가 끝났을 경우
	if k > exchange_counts:
		cards_str = ''.join(cards)
		# answer: 교환 횟수가 끝나는 모든 깊이마다의 cards 의 값 중 가장 큰 경우
		answer = max(answer, int(cards_str))
		return

	for i in range(n_cards - 1):						# 교환할 1번 카드
		for j in range(i + 1, n_cards):					# 교환할 2번 카드
			cards[i], cards[j] = cards[j], cards[i]		# 교환한다.
			cards_str = ''.join(cards)
			if cards_str not in changed[k]:				# 교환한 카드가 이번에 처음 교환해 본 숫자의 나열이면,
				changed[k].add(cards_str)				# 그 카드 상태를 기록해두고
				backtracking(k + 1)						# 그 카드 상태로 그 다음 교환을 실행한다.

			cards[i], cards[j] = cards[j], cards[i]		# 원상 복구한다.


n_tests = int(input())

for t in range(1, n_tests + 1):
	# cards: 주어진 카드, exchange_counts: 교환해야하는 횟수
	cards, exchange_counts = input().split()
	cards, exchange_counts = list(cards), int(exchange_counts)
	n_cards = len(cards)

	# 교환 횟수(인덱스) 에 따라 changed 에 cards 의 경우의 수를 저장한다.
	changed = [set() for _ in range(11)]
	changed[0].add(''.join(cards))

	# Backtracking
	answer = 0
	backtracking(1)

	print(f"#{t}", answer)
