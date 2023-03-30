# BOJ_1715 : 카드 정렬하기
import heapq

# Input
N = int(input())
cards = []
for _ in range(N):
    cards.append(int(input()))
heapq.heapify(cards)

res = 0
while len(cards) > 1:
    sum_cards = heapq.heappop(cards) + heapq.heappop(cards)
    cards.append(sum_cards)
    res += sum_cards

print(res)