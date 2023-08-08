# BOJ_2477 : 참외밭
import sys

n_oriental_melon = int(sys.stdin.readline())
direction_perimeter = [list(map(int, sys.stdin.readline().split())) for _ in range(6)]
# perimeters_dict: -> key: 방향, value: 둘레의 길이
perimeters_dict = {1: [], 2: [], 3: [], 4: []}
# 각각 방향과, 둘레만 담은 리스트를 두 배로 확장
directions_x2, perimeters_x2 = [], []
for data in direction_perimeter:
    perimeters_dict[data[0]].append(data[1])
    directions_x2.append(data[0])
    perimeters_x2.append(data[1])
directions_x2 *= 2
perimeters_x2 *= 2

# 큰 사각형의 둘레를 담을 리스트
large_perimeters = []
# 작은 사각형의 방향과 둘레를 담을 리스트
short_direction, short_perimeters = [], []
for direction, data in perimeters_dict.items():
    if len(data) == 1:                      # 1. 딕셔너리(perimeters_dict)에 담긴 둘레 리스트
        large_perimeters.append(data[0])    # 길이가 1 이면 큰 사각형의 둘레이다.
    else:                                   # 2. 아닌 건 작은 사각형의 둘레이다.
        short_direction.append(direction)

# 둘레를 담은 리스트(directions_x2)에 작은 사각형 둘레가 나오는데,
# 어떤 방식으로 등장할지 모르므로 short_direction1, short_direction2의 두 가지 패턴을 만든다.
short_direction1 = [short_direction[0], short_direction[1]] * 2
short_direction2 = [short_direction[1], short_direction[0]] * 2
# directions_x2 를 돌면서 short_direction 의 패턴이 나오는지 확인한다.
for idx in range(9):
    if directions_x2[idx:idx + 4] == short_direction1:
        short_perimeters.append(perimeters_x2[idx + 1])
        short_perimeters.append(perimeters_x2[idx + 2])
        break
    elif directions_x2[idx:idx + 4] == short_direction2:
        short_perimeters.append(perimeters_x2[idx + 1])
        short_perimeters.append(perimeters_x2[idx + 2])
        break

large_area = large_perimeters[0] * large_perimeters[1]
short_area = short_perimeters[0] * short_perimeters[1]
area = large_area - short_area

print(area * n_oriental_melon)
