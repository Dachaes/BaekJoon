# BOJ_2980 : 도로와 신호등
import sys

n_lights, len_streets = map(int, sys.stdin.readline().split())
lights = [list(map(int, sys.stdin.readline().split())) for _ in range(n_lights)]

# pos: 현재 위치, time: 현재 시간
pos, time = 0, 0
for light in lights:
    npos, red, green = light
    # 1. 신호등 위치에 도달하는데 걸린 시간
    time += npos - pos
    pos = npos

    # 2. 신호등 기다린 시간
    waiting = time % (red + green)      # 신호등 사이클 시간을 모두 제거
    if red > waiting:                   # 2-1. 빨간 불일 때
        waiting = red - waiting
    else:                               # 2-2. 초록 불일 때
        waiting = 0
    time += waiting

# 신호등을 모두 거쳤음에도 거리 끝이 아니라면, 걸어간다.
if pos < len_streets:
    time += len_streets - pos
    pos = len_streets

print(time)