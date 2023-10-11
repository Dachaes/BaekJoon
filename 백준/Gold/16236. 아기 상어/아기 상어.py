# BOJ_16236 : 아기 상어
import sys
from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def bfs_16236(x, y):
    global eating, eating_fish, distance, shark_size

    visited = [([False] * n) for _ in range(n)]

    q = deque()
    q.append([x, y, 0])
    visited[x][y] = True
    while q:
        x, y, dist = q.popleft()
        # 1. 먹을 수 있는 물고기가 없거나, 있는데 일단 그 거리만큼까지는 완전 탐색을 할 때
        if not eating_fish or dist != eating_fish[0][2]:
            for p in range(4):
                nx, ny = x + dx[p], y + dy[p]

                if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                    visited[nx][ny] = True
                    if 0 <= arr[nx][ny] <= shark_size:
                        q.append([nx, ny, dist + 1])
                        # 1-1. 물고기를 먹을 수 있을 경우
                        if 0 < arr[nx][ny] < shark_size:
                            eating_fish.append([nx, ny, dist + 1])

        # 2. 먹을 수 있는 물고기가 있을 경우, 일단 그 거리만큼까지는 완전 탐색을 하고 아래 코드를 실행
        else:
            # 2-1. 먹은 물고기 수를 계속 상어의 크기와 비교
            eating += 1
            if eating == shark_size:
                eating = 0
                shark_size += 1

            # 2-2. 가장 좌측 상단의 물고기를 탐색
            eating_fish.sort(key=lambda z: (z[0], z[1]))
            distance += eating_fish[0][2]
            nx, ny = eating_fish[0][0], eating_fish[0][1]
            arr[nx][ny] = 0

            # 2-3. 먹을 수 있는 물고기 리스트를 비움
            eating_fish = []

            # 2-4. 다음 시작 자리부터 다시 bfs
            q.clear()
            q.append([nx, ny, 0])
            visited = [([False] * n) for _ in range(n)]


n = int(sys.stdin.readline())
arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

eating, eating_fish, distance = 0, [], 0
shark_size = 2

# 아기 상어 위치를 찾아서 bfs 를 시작한다.
for i in range(n):
    for j in range(n):
        if arr[i][j] == 9:
            arr[i][j] = 0
            bfs_16236(i, j)

print(distance)