decode = {'0001101': 0, '0011001': 1, '0010011': 2, '0111101': 3, '0100011': 4,
          '0110001': 5, '0101111': 6, '0111011': 7, '0110111': 8, '0001011': 9}


n_tests = int(input())

for t in range(1, n_tests + 1):
    x, y = map(int, input().split())
    code_line = ''
    for _ in range(x):
        data = input()
        if code_line == '' and data != '0' * y:
            code_line = data

    reverse_code = code_line[::-1]
    end_index = y - 1 - reverse_code.find('1')

    start_index = end_index - 56 + 1
    code1 = code_line[start_index:end_index + 1]

    code2 = ''
    for i in range(0, 56, 7):
        code2 += str(decode[code1[i:i+7]])

    odd, even = 0, 0
    for idx in range(0, 8, 2):
        odd += int(code2[idx])
        even += int(code2[idx + 1])
    check = odd * 3 + even

    if not check % 10:
        print(f"#{t}", odd + even)
    else:
        print(f"#{t}", 0)