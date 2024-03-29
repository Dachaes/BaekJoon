# BOJ_3190 : 뱀

len_of_board = int(input())
num_of_apples = int(input())
apples = []
for _ in range(num_of_apples):
    apples.append(list(map(int, input().split())))
num_of_rotation = int(input())
rotations = []                      # L: 왼쪽, D: 오른쪽
for _ in range(num_of_rotation):
    rotations.append(list(input().split()))


snake = [[1, 1]]
head = snake[0]

directions = ['RIGHT', 'DOWN', 'LEFT', 'UP']
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
direction = 0

time = 0
check_time = 0
while True:
    # 1. 매 초동안 뱀(snake)이 가지고 있는 방향(direction)으로 직진한다.
    next_pos = [head[0] + dx[direction], head[1] + dy[direction]]
    time += 1

    # 2-1. 다음 뱀의 머리가 향할 위치(next_pos)가 벽이 아니고, 몸과 부딪히지도 않는다면
    # 뱀 리스트(snake)의 제일 앞에 next_pos의 좌표값을 삽입하고, 뱀의 머리(head) 좌표값을 갱신한다.
    if 1 <= next_pos[0] <= len_of_board and 1 <= next_pos[1] <= len_of_board and next_pos not in snake:
        snake.insert(0, next_pos)
        head = next_pos
        # 2-1-1. 다음 뱀의 머리가 향할 위치(next_pos)에 사과가 없다면, 뱀 리스트에서 꼬리 부분 좌표를 삭제하고
        # 사과가 있다면, 사과 리스트에서 해당 사과의 좌표를 삭제한다.
        if next_pos not in apples:
            snake.pop(-1)
        else:
            apples.remove(next_pos)
    # 2-2. 다음 뱀의 머리가 향할 위치(next_pos)가 벽이거나 몸과 부딪힌다면 게임을 종료한다.
    else:
        break

    # 3. 일정 시간 이후에 방향 변환 정보를 확인하여 뱀의 방향을 바꾼다.
    if check_time < len(rotations) and time == int(rotations[check_time][0]):
        if rotations[check_time][1] == 'L':
            direction = (direction - 1) % 4
        else:
            direction = (direction + 1) % 4
        check_time += 1

print(time)