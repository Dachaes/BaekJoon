# isp: in-stack priority, icp: in-coming priority
isp = {'(': 0, '*': 2, '/': 2, '+': 1, '-': 1}
icp = {'(': 3, '*': 2, '/': 2, '+': 1, '-': 1}


# 중위 표기식을 후위 표기식으로 변환하는 함수
def convert_postfix_notation(notation):
    stack, res_notation = [], []
    for x in notation:
        # 1. x가 숫자일 때, 바로 후위 표기식(res_notation)으로 출력한다.
        if x not in ['(', '*', '/', '+', '-', ')']:
            res_notation.append(int(x))
        # 2. x가 ')'일 때, '('가 나올 때까지 stack을 pop한다.
        elif x == ')':
            pre_x = stack.pop()
            while pre_x != '(':
                res_notation.append(pre_x)
                pre_x = stack.pop()
        # 3. x가 숫자도, ')'도 아니면, 우선 순위에 따라서 append, pop을 한다.
        else:
            # 3-1. stack이 비어있거나, x 가 stack에 있는 값보다 우선순위가 높으면
            # stack에 저장(append)한다.
            if not stack or isp[stack[-1]] < icp[x]:
                stack.append(x)
            # 3-2. x가 stack에 있는 값이랑 우선순위가 같거나 낮으면
            # 그 동안 stack에 있는 값을 pop하고, 후위 표기식으로 출력한다.
            # 마지막에 x를 stack에 저장한다.
            elif isp[stack[-1]] >= icp[x]:
                while stack and isp[stack[-1]] >= icp[x]:
                    pre_x = stack.pop()
                    res_notation.append(pre_x)
                stack.append(x)
    else:
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