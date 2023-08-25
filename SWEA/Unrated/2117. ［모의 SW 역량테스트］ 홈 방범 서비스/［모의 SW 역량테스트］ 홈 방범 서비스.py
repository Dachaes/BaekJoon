dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


# x, y: 기준점, max_depth: BFS 의 depth
# res: 함수의 반환값 -> 해당 범위 내의 최대 house 의 개수
def houses_in_k_area(x, y, max_depth):
    queue = [(x, y)]
    depth, res = 1, 0

    visited = [[0] * n_city for _ in range(n_city)]
    visited[x][y] = depth
    # 처음 위치(x, y) 에 집이 있으면, result 에 counting 한다.
    if city[x][y]:
        res += 1

    while queue:
        x, y = queue.pop(0)
        depth = visited[x][y]

        # 보안 범위 (max_depth = k) 만큼 탐색을 완료했으면, whlie 문(BFS 탐색) 을 종료한다.
        if depth == max_depth:
            break

        # 현재 기준점(x, y) 에서 4 방향의 nx, ny 를 확인하며
        # 방문하지 않은 곳으로 BFS 탐색을 최종적으로 depth 만큼 한다.
        for p in range(4):
            nx, ny = x + dx[p], y + dy[p]
            if 0 <= nx < n_city and 0 <= ny < n_city and not visited[nx][ny]:
                visited[nx][ny] = depth + 1
                queue.append((nx, ny))
                # 방문할 위치(nx, ny) 에 집이 있으면, result 에 counting 한다.
                if city[nx][ny]:
                    res += 1

    return res


n_tests = int(input())

for t in range(1, n_tests + 1):
    # n_city: 도시의 크기, income: 각 집마다 지불하는 비용
    # city: 도시의 정보
    n_city, income = map(int, input().split())
    city = [list(map(int, input().split())) for _ in range(n_city)]

    # k: 방범 운영 범위 상수 (k = 1 ~ )
    k, max_k = 1, n_city + (n_city // 2) + 2
    result = 0
    while True:
        # n_houses: 운영 범위(k) 가 고정되었을 때, 얼마나 많은 집을 지킬 수 있는가
        # (기준의 되는 위치를 바꾸며, 항상 최대값을 확인)
        n_houses = 0
        # expenses: 서비스 운영 비용, profit: 서비스를 제공하고 얻는 수익
        expenses, profit = k * k + (k - 1) * (k - 1), 0

        for i in range(n_city):
            for j in range(n_city):
                # 1. 매 방범 운영 범위(기준은 for 문을 돌며 바뀜)에 집이 얼마나 존재하는지 확인한다.
                n_houses = max(n_houses, houses_in_k_area(i, j, k))

        # 2. k 가 고정되었을 때, 최대로 얻을 수 있는 수익을 계산한다.
        # 손해가 없다면, result 값에 최대 집의 개수를 저장해놓는다.
        profit = income * n_houses - expenses
        if profit >= 0:
            result = n_houses
            
        # 만약 max_k 에 k 가 도달하면, while 문을 종료하며 결과를 출력한다.
        if k == max_k:
            print(f"#{t}", result)
            break
        else:
            k += 1