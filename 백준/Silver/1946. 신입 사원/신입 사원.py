# BOJ_1946 : 신입 사원
import sys

# Input
n_tests = int(sys.stdin.readline())

for _ in range(n_tests):
    n_applicants = int(sys.stdin.readline())
    applicants = [list(map(int, sys.stdin.readline().split())) for _ in range(n_applicants)]

    applicants.sort()
    applicant1 = applicants[0]      # 시험 1, 1등의 성적 리스트

    count = 0
    test2_standard = applicant1[1]  # 시험 2의 성적 기준점
    for applicant in applicants:
        test2_applicant = applicant[1]
        if test2_applicant <= test2_standard:
            test2_standard = test2_applicant
            count += 1

    print(count)