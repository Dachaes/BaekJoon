# BOJ_3613 : Java vs C++
import sys


def convert_type(string):
    pre_letter = string[0]
    if pre_letter.isupper() or pre_letter == "_" or string[-1] == "_":
        return 'Error!'

    snake_case, camelCase = False, False
    res_string = pre_letter
    for letter in string[1:]:
        # 타입관련 확인
        if not snake_case and letter == '_':
            snake_case = True
        if not camelCase and letter.isupper():
            camelCase = True
        if snake_case and camelCase:
            return 'Error!'

        # 이름 변환
        if pre_letter.isalpha() and letter == '_':
            pre_letter = letter
            continue
        elif pre_letter == '_' and letter == '_':
            return 'Error!'
        elif pre_letter == '_' and letter.islower():
            res_string += letter.upper()
        elif letter.isupper():
            res_string += '_' + letter.lower()
        else:
            res_string += letter

        pre_letter = letter

    return res_string


name = list(str(sys.stdin.readline().rstrip()))
converted_name = convert_type(name)

print(converted_name)