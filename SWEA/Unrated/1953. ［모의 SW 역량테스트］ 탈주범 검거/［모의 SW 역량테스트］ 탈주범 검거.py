pipe_types = {1: [[0, 0], [-1, 0], [1, 0], [0, -1], [0, 1]],
              2: [[0, 0], [-1, 0], [1, 0]],
              3: [[0, 0], [0, -1], [0, 1]],
              4: [[0, 0], [-1, 0], [0, 1]], 5: [[0, 0], [1, 0], [0, 1]],
              6: [[0, 0], [1, 0], [0, -1]], 7: [[0, 0], [-1, 0], [0, -1]]}


def bfs(k):
    # 종료 조건: 탈출 시간 이상을 볼 필요는 없다.
    if k > escape_time:
        return

    pos = visited[k - 1]                            # pos: 현재 시간 대의 모든 경우의 위치
    for p in pos:
        x, y = p                                    # pos 리스트에서 하나의 리스트(x, y 위치)만 가져온다.
        pipe = underground[x][y]                    # 현재 보고 있는 위치의 파이프 타입

        for pipe_type in pipe_types[pipe]:          # 현재 위치의 파이프 타입에 따른, 즉 다음 위치를 정해 줄 dx, dy 를 꺼내온다.
            dx, dy = pipe_type[0], pipe_type[1]
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m:         # 다음 위치의 파이프가 범위 내에 있고,
                next_pipe = underground[nx][ny]     # 그 다음 파이프의 타입이
                if next_pipe and [-dx, -dy] in pipe_types[next_pipe]:       # 지금 위치의 파이프 타입과 이어져 있을 때
                    visited[k].add((nx, ny))        # 경우의 수를 추가한다.

    # 해당 시간대의 위치를 모두 체크해줬으면
    # 그 시간대의 위치에 따른 다음 위치를 보러간다.
    bfs(k + 1)


n_tests = int(input())

for t in range(1, n_tests + 1):
    n, m, start_n, start_m, escape_time = map(int, input().split())
    underground = [list(map(int, input().split())) for _ in range(n)]

    # 방문 깊이에 따라 위치를 관리할 리스트
    visited = [set() for _ in range(21)]
    visited[1].add((start_n, start_m))

    # 탈출 2시간 째부터 탐색한다.
    bfs(2)

    result = len(visited[escape_time])
    print(f"#{t}", result)
