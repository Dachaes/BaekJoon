# BOJ_9461 : 파도반 수열
import sys

num_tests = int(sys.stdin.readline())
n_list = []
for _ in range(num_tests):
    n_list.append(int(sys.stdin.readline()))


def seq(num):
    global sequence
    if sequence[num] == -1:
        sequence[num] = seq(num - 1) + seq(num - 5)

    return sequence[num]


sequence = [0, 1, 1, 1, 2, 2] + ([-1] * 95)
for n in n_list:
    print(seq(n))