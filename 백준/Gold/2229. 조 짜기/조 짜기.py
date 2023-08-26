# BOJ_2229 : 조짜기
import sys

# input
n_students = int(sys.stdin.readline())
students_point = list(map(int, sys.stdin.readline().split()))

dp = [0] * (n_students + 1)
for i in range(1, n_students + 1):
    if i == 1:
        dp[i] = 0
    elif i == 2:
        dp[i] = abs(students_point[0] - students_point[1])
    else:
        dp[i] = dp[i - 1]
        for j in range(1, i - 1):
            dp[i] = max(dp[i], dp[j] + abs(max(students_point[j:i]) - min(students_point[j:i])))

print(dp[n_students])