# BOJ_13300 : 방 배정
import sys

n_students, max_people_in_room = map(int, sys.stdin.readline().split())
students = [list(map(int, sys.stdin.readline().split())) for _ in range(n_students)]
rooms = {'여1': 0, '여2': 0, '여3': 0, '여4': 0, '여5': 0, '여6': 0,
               '남1': 0, '남2': 0, '남3': 0, '남4': 0, '남5': 0, '남6': 0}

for student in students:
    sex, grade = student[0], student[1]
    if sex == 0:
        rooms[f'여{grade}'] += 1
    else:
        rooms[f'남{grade}'] += 1

count = 0
for room in rooms.values():
    if room == 0:
        continue
    count += (room + 1) // 2

print(count)