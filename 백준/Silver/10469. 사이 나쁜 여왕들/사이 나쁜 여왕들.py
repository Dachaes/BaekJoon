# boj_10469 : 사이 나쁜 여왕들
import sys


def is_promising(q):
    for i in range(8):
        for j in range(i):
            # 1. 해당 행에 이미 퀸이 있을 경우에 유망하지 않다.
            # ex. (0, 0) 과 (1, 0)
            if q[i] == q[j]:
                return 'invalid'
            # 2. 대각선 라인에 이미 퀸이 있을 경우에 유망하지 않다.
            # ex. (0, 0) 과 (1, 1) / (1, 1) 과 (0, 2)
            if abs(i - j) == abs(q[i] - q[j]):
                return 'invalid'

    return 'valid'


# input
queens = [sys.stdin.readline().strip() for _ in range(8)]

result = ''
for i in range(8):
    for j in range(8):
        if queens[i][j] == '*':
            queens[i] = j
            break
    else:
        queens[i] = -1
        result = 'invalid'
        break

if not result:
    result = is_promising(queens)
print(result)