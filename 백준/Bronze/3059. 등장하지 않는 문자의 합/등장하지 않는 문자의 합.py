# BOJ_3059 : 등장하지 않는 문자의 합
import sys

n_tests = int(sys.stdin.readline())

alphabet = []
for i in range(65, 91):
    alphabet.append(chr(i))

for _ in range(n_tests):
    sum_ASCII = 0
    string = sys.stdin.readline().rstrip()
    for alpha in alphabet:
        if alpha not in string:
            sum_ASCII += ord(alpha)

    print(sum_ASCII)