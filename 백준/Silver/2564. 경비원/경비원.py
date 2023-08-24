# BOJ_2564 : 경비원
import sys

# input
row, col = map(int, sys.stdin.readline().split())
n_stores = int(sys.stdin.readline())
# stores: 가게 정보를 저장
stores = [list(map(int, sys.stdin.readline().split())) for _ in range(n_stores)]
my_dir, my_pos = map(int, sys.stdin.readline().split())

sum_min_pos = 0
for store in stores:
    store_dir, store_pos = store
    # 내 위치랑 상점 위치가 같은 위치일 때
    if my_dir == store_dir:
        min_pos = abs(store_pos - my_pos)
        sum_min_pos += min_pos

    # 내 위치랑 상점 위치가 맞은 편일 때
    elif my_dir * store_dir in [2, 12]:
        if my_dir * store_dir == 2:
            min_pos1 = col + my_pos + store_pos
            min_pos2 = col + row - my_pos + row - store_pos
        elif my_dir * store_dir == 12:
            min_pos1 = row + my_pos + store_pos
            min_pos2 = row + col - my_pos + col - store_pos
        sum_min_pos += min(min_pos1, min_pos2)

    # 그외
    else:
        if my_dir * store_dir == 3:
            min_pos = my_pos + store_pos
        elif my_dir * store_dir == 4:
            if my_dir == 1:
                min_pos = row - my_pos + store_pos
            elif my_dir == 4:
                min_pos = row - store_pos + my_pos
        elif my_dir * store_dir == 6:
            if my_dir == 2:
                min_pos = my_pos + col - store_pos
            elif my_dir == 3:
                min_pos = store_pos + col - my_pos
        elif my_dir * store_dir == 8:
            min_pos = row - my_pos + col - store_pos
        sum_min_pos += min_pos

print(sum_min_pos)