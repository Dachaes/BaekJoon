# BOJ_18870 : 좌표 압축
import sys

N = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))
sorted_numbers = sorted(set(numbers))

sorted_num_dict = {sorted_numbers[i]: i for i in range(len(sorted_numbers))}

new_numbers = []
for number in numbers:
    new_numbers.append(sorted_num_dict[number])

print(*new_numbers)