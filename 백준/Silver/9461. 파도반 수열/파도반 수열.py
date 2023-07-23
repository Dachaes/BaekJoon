# BOJ_9461 : 파도반 수열
import sys

num_tests = int(sys.stdin.readline())
n_list = []
for _ in range(num_tests):
    n_list.append(int(sys.stdin.readline()))


def seq(num):
    global sequence
    if sequence[num] == -1:
        if 1 <= num < 4:
            sequence[num] = 1
        elif 4 <= num < 6:
            sequence[num] = 2
        else:
            sequence[num] = seq(num - 1) + seq(num - 5)

    return sequence[num]


sequence = [-1] * 101
for n in n_list:
    print(seq(n))