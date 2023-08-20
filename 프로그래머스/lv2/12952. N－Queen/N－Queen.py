def is_promising(q, x, y):
    for i in range(x):
        # 1. 해당 행에 이미 퀸이 있을 경우에 유망하지 않다.
        # ex. (0, 0) 과 (1, 0)
        # 2. 대각선 라인에 이미 퀸이 있을 경우에 유망하지 않다.
        # ex. (0, 0) 과 (1, 1) / (1, 1) 과 (0, 2)
        if y == q[i] or abs(x - i) == abs(y - q[i]):
            return False
    return True


def n_queen(q, x, n, cnt):
    for y in range(n):
        if is_promising(q, x, y):   # (x, y) 위치가 유망하다면,
            if x < n - 1:           # (x, y) 위치에 queen 이 존재할 수 있다.
                q[x] = y
                cnt = n_queen(q, x + 1, n, cnt)
                q[x] = -1
            else:                   # 마지막 행(재귀)면 더 이상 재귀하지 않고,
                cnt += 1            # counting 만 한다.
    return cnt


def solution(n):
    # N = 3 일 때, queen 은 [-1, -1, -1] 의 값을 가지고,
    # 이는 각 행마다 어떤 열에 queen 이 존재하는가를 나타낸다.
    # queen = [0, 2, 1] 이면 queen 은 [(0, 1), (1, 2), (2, 1)] 에 서 있다.
    queen = [-1] * n
    count = n_queen(queen, 0, n, 0)

    return count