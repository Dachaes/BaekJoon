# BOJ_5176 : 대회 자리
import sys

n_cases = int(sys.stdin.readline())

answers = []
for _ in range(n_cases):
    n_participants, n_seats = map(int, sys.stdin.readline().split())
    seats = []
    for _ in range(n_participants):
        seats.append(int(sys.stdin.readline()))
    seats_set = set(seats)
    len_seats_in_use = len(seats_set)

    answers.append(n_participants - len_seats_in_use)

for answer in answers:
    print(answer)