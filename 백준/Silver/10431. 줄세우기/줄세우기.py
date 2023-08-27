# BOJ_10431 : 줄 세우기
import sys

# input
n_tests = int(sys.stdin.readline())

for t in range(1, n_tests + 1):
    test, *students = map(int, sys.stdin.readline().split())
    checked_students = []

    result = 0
    for student in students:
        for checked_student in checked_students:
            if checked_student > student:
                result += 1
        checked_students.append(student)

    print(f'{t}', result)