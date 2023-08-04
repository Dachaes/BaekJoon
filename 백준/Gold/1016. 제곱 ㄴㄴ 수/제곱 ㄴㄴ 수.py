# BOJ_1016 : 제곱 ㄴㄴ수
import sys

min_value, max_value = list(map(int, sys.stdin.readline().split()))
between_min_max = [True] * (max_value - min_value + 1)

for i in range(2, 10 ** 6 + 1):
    squared = i * i
    
    # 주어진 between_min_num 사이에 있는 제일 첫번째 제곱수 찾기
    first_square = ((min_value + squared - 1) // squared) * squared

    for j in range(first_square, max_value + 1, squared):
        between_min_max[j - min_value] = False

print(sum(between_min_max))