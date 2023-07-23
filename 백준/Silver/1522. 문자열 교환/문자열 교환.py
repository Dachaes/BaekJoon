# BOJ_1522 : 문자열 교환
import sys
INF = 1e9


def shift_right(input_str):
    global len_str
    result = input_str[-1] + input_str[:len_str - 1]
    return result


# Input
string = sys.stdin.readline()

cnt_a, cnt_b = string.count('a'), string.count('b')
len_str = cnt_a + cnt_b
sorted_string = 'a' * cnt_a + 'b' * cnt_b

min_exchange = INF
for _ in range(len_str):
    sorted_string = shift_right(sorted_string)
    cnt = 0
    for i in range(len_str):
        if string[i] != sorted_string[i]:
            cnt += 1
    min_exchange = min(min_exchange, cnt // 2)

print(min_exchange)