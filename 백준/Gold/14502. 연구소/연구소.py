# BOJ_14502 : 연구소
import sys
from itertools import combinations

# Input
n, m = map(int, sys.stdin.readline().split())
lab = []
for _ in range(n):
    lab_data = list(map(int, sys.stdin.readline().split()))
    lab.append(lab_data)

empty_space = []
cnt_empty = 0
safety_zone = 0
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


# 원본의 연구실을 복제하여 새 연구실 생성하는 함수
def replicate(origin, num):
    new_wall = possible_comb[num]
    replica = []
    for i in range(n):
        temp = []
        for j in range(m):
            set_up_new_wall = 0
            for k in range(3):
                if new_wall[k][0] == i and new_wall[k][1] == j:
                    set_up_new_wall = 1
            if set_up_new_wall:
                temp.append(1)
            else:
                temp.append(origin[i][j])
        replica.append(temp)
    return replica


# 복제한 연구실을 오염시키는 함수
def contaminate(x, y):
    for k in range(4):
        new_x, new_y = x + dx[k], y + dy[k]
        if (0 <= new_x < n and 0 <= new_y < m) and new_lab[new_x][new_y] == 0:
            new_lab[new_x][new_y] = 2
            contaminate(new_x, new_y)


# 원본의 연구실에서 빈 공간(0)의 위치를 empty_space 리스트에 저장한다.
for i in range(n):
    for j in range(m):
        if lab[i][j] == 0:
            empty_space.append([i, j])

# empty_space의 조합을 가져온다. (벽을 3개 세울 수 있는 모든 경우의 수)
possible_comb = list(combinations(empty_space, 3))
num_comb = len(possible_comb)

# 모든 경우의 수를 체크한다. (num_comb가 0일 때까지)
cnt = 0
while num_comb != 0:
    new_lab = replicate(lab, cnt)
    new_safety_zone = 0

    for i in range(n):
        for j in range(m):
            if new_lab[i][j] == 2:
                contaminate(i, j)

    for i in range(n):
        for j in range(m):
            if new_lab[i][j] == 0:
                new_safety_zone += 1

    safety_zone = max(safety_zone, new_safety_zone)
    cnt += 1
    num_comb -= 1
print(safety_zone)