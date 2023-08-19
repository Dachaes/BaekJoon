# boj_1918 : 후위 표기식
import sys

isp = {'(': 0, '*': 2, '/': 2, '+': 1, '-': 1}
icp = {'(': 3, '*': 2, '/': 2, '+': 1, '-': 1}

notation = list(sys.stdin.readline().strip())

stack = []
postfix_notation = []
for x in notation:
    if x not in ['(', '*', '/', '+', '-', ')']:
        postfix_notation.append(x)
    elif x == ')':
        pre_x = stack.pop()
        while pre_x != '(':
            postfix_notation.append(pre_x)
            pre_x = stack.pop()
    else:
        if not stack or isp[stack[-1]] < icp[x]:
            stack.append(x)
        else:
            while stack and isp[stack[-1]] >= icp[x]:
                pre_x = stack.pop()
                postfix_notation.append(pre_x)
            stack.append(x)

while stack:
    postfix_notation.append(stack.pop())

print(''.join(postfix_notation))