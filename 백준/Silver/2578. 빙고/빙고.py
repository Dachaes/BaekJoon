# BOJ_2578 : 빙고
import sys
from copy import deepcopy

# paper: 빙고판
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(5)]
# callings: 사회자가 부른 숫자
input_callings = [list(map(int, sys.stdin.readline().split())) for _ in range(5)]
callings = []
for calling in input_callings:
    callings += calling


def call_number(board, number):
    for i in range(5):
        for j in range(5):
            if board[i][j] == number:
                board[i][j] = 0
    return board


def how_many_lines(board):
    count_lines = 0
    # 1. 가로 행
    for i in range(5):
        if sum(board[i]) == 0:
            count_lines += 1

    # 2. 세로 행
    board_T = deepcopy(board)
    for i in range(5):
        for j in range(5):
            if i > j:
                board_T[i][j], board_T[j][i] = board_T[j][i], board_T[i][j]
    for i in range(5):
        if sum(board_T[i]) == 0:
            count_lines += 1

    # 3. 대각선
    diagonal1, diagonal2 = 0, 0
    for i in range(5):
        diagonal1 += board[i][4 - i]
        diagonal2 += board[i][i]
    if diagonal1 == 0:
        count_lines += 1
    if diagonal2 == 0:
        count_lines += 1

    return count_lines


count = None
for cnt_calling, calling in enumerate(callings):
    paper = call_number(paper, calling)
    if how_many_lines(paper) >= 3:
        count = cnt_calling + 1
        break

print(count)
