# isp: in-stack priority, icp: in-coming priority
isp = {'(': 0, '*': 2, '/': 2, '+': 1, '-': 1}
icp = {'(': 3, '*': 2, '/': 2, '+': 1, '-': 1}


# 중위 표기식을 후위 표기식으로 변환하는 함수
def convert_postfix_notation(nota):
    stack, res_notation = [], []
    for x in nota:
        if x not in ['(', '*', '/', '+', '-', ')']:
            res_notation.append(int(x))
        elif x == ')':
            pre_x = stack.pop()
            while pre_x != '(':
                res_notation.append(pre_x)
                pre_x = stack.pop()
        else:
            while stack and isp[stack[-1]] >= icp[x]:
                pre_x = stack.pop()
                res_notation.append(pre_x)
            stack.append(x)

    if stack:
        pre_x = stack.pop()
        res_notation.append(pre_x)

    return res_notation


# 후위 표기식을 계산하는 함수
def calculate_postfix_notation(notation):
    stack, res = [], 0
    for x in notation:
        # 1. x가 숫자이면 stack에 임시 저장한다.
        if x not in ['*', '/', '+', '-']:
            stack.append(x)
        else:
            op2, op1 = stack.pop(), stack.pop()
            if x == '*':
                stack.append(op1 * op2)
            elif x == '/':
                stack.append(op1 // op2)
            elif x == '+':
                stack.append(op1 + op2)
            else:
                stack.append(op1 - op2)

    res = stack[-1]
    return res


n_tests = 10

for t in range(1, n_tests + 1):
    len_notation = int(input())
    infix_notation = list(input())

    # print(*infix_notation)
    postfix_notation = convert_postfix_notation(infix_notation)
    # print(*postfix_notation)
    result = calculate_postfix_notation(postfix_notation)

    print(f"#{t}", result)