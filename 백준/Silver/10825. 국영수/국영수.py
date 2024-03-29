# BOJ_10825 : 국영수

# Input
num = int(input())
students = []
for _ in range(num):
    data = input().split()
    students.append([data[0], int(data[1]), int(data[2]), int(data[3])])

students.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))

for student in students:
    print(student[0])