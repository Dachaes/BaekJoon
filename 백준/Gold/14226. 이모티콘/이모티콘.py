# BOJ_14226 : 이모티콘
# https://data-flower.tistory.com/80
import sys
from collections import deque

goal = int(sys.stdin.readline())

dict = dict()

# 이모티콘 1개, 클립보드 0개 => 시간 0초
dict[(1, 0)] = 0
q = deque([(1, 0)])

while q:
    emoji, clip = q.popleft()
    time = dict[(emoji, clip)]

    # 종료 조건 : emoji 가 목표한 갯수가 되었을 때
    if emoji == goal:
        print(time)
        break

    # 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
    if (emoji, emoji) not in dict.keys():
        dict[(emoji, emoji)] = time + 1
        q.append((emoji, emoji))

    # 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
    if (emoji + clip, clip) not in dict.keys():
        dict[(emoji + clip, clip)] = time + 1
        q.append((emoji + clip, clip))

    # 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
    if (emoji - 1, clip) not in dict.keys():
        dict[(emoji - 1, clip)] = time + 1
        q.append((emoji - 1, clip))