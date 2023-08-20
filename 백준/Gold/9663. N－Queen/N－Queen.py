# boj_9663 : N-Queen
import sys


def is_promising(x, y):
    global queen
    for i in range(x):
        if queen[i] != -1:
            # 1. 해당 행에 이미 퀸이 있을 경우에 유망하지 않다.
            # ex. (0, 0) 과 (1, 0)
            if y == queen[i]:
                return False
            # 2. 대각선 라인에 이미 퀸이 있을 경우에 유망하지 않다.
            # ex. (0, 0) 과 (1, 1) / (1, 1) 과 (0, 2)
            if abs(x - i) == abs(y - queen[i]):
                return False

    return True


def n_queen(x, n):
    global queen, count

    for y in range(n):
        if is_promising(x, y):      # (x, y) 위치가 유망하다면, 
            if x < n - 1:           # (x, y) 위치에 queen 이 존재할 수 있다.
                queen[x] = y
                n_queen(x + 1, n)
                queen[x] = -1
            else:                   # 마지막 행(재귀)면 더 이상 재귀하지 않고,
                count += 1          # counting 만 한다.


# input
N = int(sys.stdin.readline())

count = 0
# N = 3 일 때, queen 은 [-1, -1, -1] 의 값을 가지고,
# 이는 각 행마다 어떤 열에 queen 이 존재하는가를 나타낸다.
# queen = [0, 2, 1] 이면 queen 은 [(0, 1), (1, 2), (2, 1)] 에 서 있다.
queen = [-1] * N
n_queen(0, N)

print(count)