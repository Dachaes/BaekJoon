# BOJ_17471 : 게리맨더링
import sys


# 조합을 구하는 함수
def combinations():
    cnt, combs1, combs2 = 0, [], []
    for i in range(1, (1 << N) // 2):
        comb1, comb2 = [], []
        for j in range(N):
            if i & (1 << j):
                comb1.append(j + 1)
            else:
                comb2.append(j + 1)

        if is_available(comb1, comb2):
            cnt += 1
            combs1.append(comb1)
            combs2.append(comb2)

    return [cnt, combs1, combs2]


# 부분 집합 A 와 부분 집합 B 가 선거구 두 개로 나뉘는지 확인하는 함수
def is_available(A, B):
    visited = [True] + [False] * N

    # dfs-A
    stack = [A[0]]
    visited[A[0]] = True
    while stack:
        pos = stack[-1]
        for next_pos in graph[pos]:
            if not visited[next_pos] and next_pos in A:
                stack.append(next_pos)
                visited[next_pos] = True
                break
        else:
            stack.pop()

    # dfs-B
    stack = [B[0]]
    visited[B[0]] = True
    while stack:
        pos = stack[-1]
        for next_pos in graph[pos]:
            if not visited[next_pos] and next_pos in B:
                stack.append(next_pos)
                visited[next_pos] = True
                break
        else:
            stack.pop()

    if all(visited):
        return True
    else:
        return False


# 부분 집합 A와, 부분 집합 B의 인구 수를 계산하는 함수
def calculate_population(A, B):
    pop_A, pop_B = 0, 0
    for a in A:
        pop_A += populations[a]
    for b in B:
        pop_B += populations[b]

    diff = abs(pop_A - pop_B)
    return diff


N = int(sys.stdin.readline())
populations = [0] + list(map(int, sys.stdin.readline().split()))
graph = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
    graph[i] = list(map(int, sys.stdin.readline().split()))[1:]

result = 100 * 10
count, cities_A, cities_B = combinations()

# 최소 인구 수 차이 찾기
for i in range(count):
    difference = calculate_population(cities_A[i], cities_B[i])
    # if not difference:
    #     result = 0
    #     print(result)
    #     break
    result = min(result, difference)

if result == 100 * 10:
    result = -1
#     print(result)
# else:
#     print(result)

print(result)