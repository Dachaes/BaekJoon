# BOJ_2884 : 알람 시계
import sys

now_h, now_m = map(int, sys.stdin.readline().split())

flag = False
hours = [i for i in range(0, 24)]
minutes = [i for i in range(0, 60)]

# 1. 분 구하기
alarm_m = minutes[now_m - 45]
if now_m < alarm_m:
    flag = True

# 2. 시간 구하기
alarm_h = now_h
if flag:
    alarm_h = hours[now_h - 1]

print(alarm_h, alarm_m)
