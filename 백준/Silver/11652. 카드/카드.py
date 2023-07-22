# BOJ_11652 : 카드
import sys

num_cards = int(sys.stdin.readline())
cards = {}
for _ in range(num_cards):
    input_data = int(sys.stdin.readline())
    # 0. 카드를 dictionary 형태로 저장한다. -> key: 카드의 숫자, value: 해당 숫자 카드의 개수
    if input_data not in cards.keys():
        cards[input_data] = 1
    else:
        cards[input_data] += 1

# 1. 가장 많이 가지고 있는 숫자 카드의 개수를 저장한다.
max_number = max(cards.values())

# 2. key, value 의 값을 바꾼 dictionary 를 만든다.
convert_cards = {}
for key, value in cards.items():
    if value not in convert_cards.keys():
        convert_cards[value] = [key]
    else:
        convert_cards[value].append(key)

# 3. 1번에서 구한 max_number 의 값으로 그 개수만큼 있는 숫자 카드가 무엇인지 구한다.
result = min(convert_cards[max_number])
print(result)
