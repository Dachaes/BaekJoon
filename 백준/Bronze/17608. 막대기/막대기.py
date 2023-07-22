# BOJ_17608 : 막대기
import sys

num_sticks = int(sys.stdin.readline())
sticks = []
for _ in range(num_sticks):
    sticks.append(int(sys.stdin.readline()))
sticks.reverse()

result, longest_stick = 0, 0
for stick in sticks:
    if longest_stick < stick:
        longest_stick = stick
        result += 1

print(result)