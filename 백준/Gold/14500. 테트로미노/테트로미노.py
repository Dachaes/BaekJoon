# BOJ_14500 : 테트로미노
import sys

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def dfs(x, y, dep, res):
    global result
    if dep == 4:
        result = max(result, res)
        return

    for p in range(4):
        nx, ny = x + dx[p], y + dy[p]
        if 0 <= nx < n and 0 <= ny < m:
            if not used[nx][ny]:
                used[nx][ny] = True
                dfs(nx, ny, dep + 1, res + arr[nx][ny])
                used[nx][ny] = False


n, m = map(int, sys.stdin.readline().split())
arr, used = [], []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))
    used.append([False] * m)

# dfs depth4 확인
result = 0
for i in range(n):
    for j in range(m):
        used[i][j] = True
        dfs(i, j, 1, arr[i][j])
        used[i][j] = False

# dfs depth4 예외1: ㅗ, ㅜ 모양 확인
for i in range(n):
    for j in range(m - 2):
        res = arr[i][j] + arr[i][j + 1] + arr[i][j + 2]
        pi, pj = i - 1, j + 1
        if 0 <= pi < n:
            res += arr[pi][pj]
            result = max(result, res)
            res -= arr[pi][pj]
        pi, pj = i + 1, j + 1
        if 0 <= pi < n:
            res += arr[pi][pj]
            result = max(result, res)

# dfs depth4 예외2: ㅓ, ㅏ 모양 확인
for i in range(n - 2):
    for j in range(m):
        res = arr[i][j] + arr[i + 1][j] + arr[i + 2][j]
        pi, pj = i + 1, j - 1
        if 0 <= pj < m:
            res += arr[pi][pj]
            result = max(result, res)
            res -= arr[pi][pj]
        pi, pj = i + 1, j + 1
        if 0 <= pj < m:
            res += arr[pi][pj]
            result = max(result, res)

print(result)
