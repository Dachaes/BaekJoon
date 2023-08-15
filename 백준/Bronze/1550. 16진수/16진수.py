# BOJ_1550 : 16진수
import sys

numbers = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}
input_number = list(sys.stdin.readline().rstrip())
input_number.reverse()

res_number = 0
for index, value in enumerate(input_number):
    if value in numbers.keys():
        number = numbers[value]
    else:
        number = int(value)

    res_number += (16 ** index) * int(number)

print(res_number)