# BOJ_1612 : 가지고 노는 1
import sys

# Input
number = int(sys.stdin.readline().rstrip())
rem, res = 0, -1
rem_list = set()

cnt = 1
while True:
    rem = (rem * 10 + 1) % number
    if rem == 0:
        res = cnt
        break
    
    if rem not in rem_list:
        rem_list.add(rem)
        cnt += 1
    else:
        break


print(res)