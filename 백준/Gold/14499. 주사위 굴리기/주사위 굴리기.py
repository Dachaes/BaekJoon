# BOJ_14499 : 주사위 굴리기
import sys

n, m, x, y, k = map(int, sys.stdin.readline().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))
movements = list(map(int, sys.stdin.readline().split()))

# 주사위의 {X, 상단, 북, 동, 서, 남, 하단} 에 저장된 값
dice = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}

# 현재 위치
pos = [x, y]

num = arr[x][y]
if num:
    dice[6] = num

for mo in movements:
    # 동쪽으로 이동
    if mo == 1:
        next_pos = [pos[0], pos[1] + 1]
        if next_pos[1] < m:
            pos = next_pos
            dice = {0: 0, 1: dice[4], 2: dice[2], 3: dice[1], 4: dice[6], 5: dice[5], 6: dice[3]}

            num = arr[next_pos[0]][next_pos[1]]
            if num:
                dice[6] = num
                arr[next_pos[0]][next_pos[1]] = 0
            else:
                arr[next_pos[0]][next_pos[1]] = dice[6]

            print(dice[1])

    # 서쪽으로 이동
    elif mo == 2:
        next_pos = [pos[0], pos[1] - 1]
        if 0 <= next_pos[1]:
            pos = next_pos
            dice = {0: 0, 1: dice[3], 2: dice[2], 3: dice[6], 4: dice[1], 5: dice[5], 6: dice[4]}

            num = arr[next_pos[0]][next_pos[1]]
            if num:
                dice[6] = num
                arr[next_pos[0]][next_pos[1]] = 0
            else:
                arr[next_pos[0]][next_pos[1]] = dice[6]

            print(dice[1])

    # 북쪽으로 이동
    elif mo == 3:
        next_pos = [pos[0] - 1, pos[1]]
        if 0 <= next_pos[0]:
            pos = next_pos
            dice = {0: 0, 1: dice[5], 2: dice[1], 3: dice[3], 4: dice[4], 5: dice[6], 6: dice[2]}

            num = arr[next_pos[0]][next_pos[1]]
            if num:
                dice[6] = num
                arr[next_pos[0]][next_pos[1]] = 0
            else:
                arr[next_pos[0]][next_pos[1]] = dice[6]

            print(dice[1])

    # 남쪽으로 이동
    else:
        next_pos = [pos[0] + 1, pos[1]]
        if next_pos[0] < n:
            pos = next_pos
            dice = {0: 0, 1: dice[2], 2: dice[6], 3: dice[3], 4: dice[4], 5: dice[1], 6: dice[5]}

            num = arr[next_pos[0]][next_pos[1]]
            if num:
                dice[6] = num
                arr[next_pos[0]][next_pos[1]] = 0
            else:
                arr[next_pos[0]][next_pos[1]] = dice[6]

            print(dice[1])