# boj_1935 : 후위 표기식 2
import sys
n = int(sys.stdin.readline())
notation = list(sys.stdin.readline().strip())
numbers = {}
for i in range(n):
    numbers[chr(65 + i)] = int(sys.stdin.readline())

stack = []
for x in notation:
    if x.isupper():
        stack.append(numbers[x])
    else:
        op2, op1 = stack.pop(), stack.pop()
        if x == '+':
            stack.append(op1 + op2)
        elif x == '-':
            stack.append(op1 - op2)
        elif x == '*':
            stack.append(op1 * op2)
        elif x == '/':
            stack.append(op1 / op2)

answer = stack[0]
print(f"{answer:.2f}")