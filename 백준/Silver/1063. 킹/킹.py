# BOJ_1063 : 킹
import sys

# R : 한 칸 오른쪽으로
# L : 한 칸 왼쪽으로
# B : 한 칸 아래로
# T : 한 칸 위로
# RT : 오른쪽 위 대각선으로
# LT : 왼쪽 위 대각선으로
# RB : 오른쪽 아래 대각선으로
# LB : 왼쪽 아래 대각선으로

move_type = {'R': (1, 0), 'L': (-1, 0), 'B': (0, -1), 'T': (0, 1),
             'RT': (1, 1), 'LT': (-1, 1), 'RB': (1, -1), 'LB': (-1, -1)}

pos_king, pos_stone, n_movements = sys.stdin.readline().split()
movements = [sys.stdin.readline().strip() for _ in range(int(n_movements))]
board = [[0] * 8 for _ in range(8)]

# 킹과 돌 놓기
king_x, king_y = ord(pos_king[0]) - 65, int(pos_king[1]) - 1
stone_x, stone_y = ord(pos_stone[0]) - 65, int(pos_stone[1]) - 1
board[king_x][king_y] = 1
board[stone_x][stone_y] = 2

# 킹 움직이기
for movement in movements:
    dx, dy = move_type[movement]

    # 1. 킹의 다음 위치 확인한다.
    king_nx, king_ny = king_x + dx, king_y + dy
    # 2-1. 다음 위치가 체스판 내에 있으면
    if 0 <= king_nx < 8 and 0 <= king_ny < 8:
        # 2-2. 그 위치에 돌이 있는 지 확인한다.
        if board[king_nx][king_ny] == 2:
            # 2-2-1. 그 돌의 다음 위치가 체스판 내에 있는지 확인하고, 그렇다면 킹과 돌을 이동시킨다.
            stone_nx, stone_ny = stone_x + dx, stone_y + dy
            if 0 <= stone_nx < 8 and 0 <= stone_ny < 8:
                board[king_x][king_y] = 0
                board[stone_x][stone_y] = 0
                king_x, king_y = king_nx, king_ny
                stone_x, stone_y = stone_nx, stone_ny
                board[king_x][king_y] = 1
                board[stone_x][stone_y] = 2
        # 2-3. 돌이 없다면, 그냥 그 위치로 이동한다.
        elif board[king_nx][king_ny] == 0:
            board[king_x][king_y] = 0
            king_x, king_y = king_nx, king_ny
            board[king_x][king_y] = 1

last_pos_king = [chr(king_x + 65), str(king_y + 1)]
last_pos_stone = [chr(stone_x + 65), str(stone_y + 1)]
print(''.join(last_pos_king))
print(''.join(last_pos_stone))