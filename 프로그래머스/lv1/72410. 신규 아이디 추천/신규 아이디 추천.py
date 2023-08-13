def solution(id):
    new_id, len_new_id = '', 0
    pre_letter = None
    for letter in id:
        # 1. 모든 대문자를 대응되는 소문자로 치환한다.
        if letter.isupper():
            new_id += letter.lower()
            len_new_id += 1
            pre_letter = letter
        # 2. 알파벳 소문자, 숫자, '-', '_', '.'를 제외한 모든 문자를 제거한다.
        elif not letter.islower() and not letter.isdecimal() and letter not in ['-', '_', '.']:
            continue
        # 3. 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환한다.
        elif pre_letter == '.' and letter == '.':
            continue
        else:
            new_id += letter
            len_new_id += 1
            pre_letter = letter

    # 4. 마침표(.)가 처음이나 끝에 위치한다면 제거한다.
    if new_id and new_id[-1] == '.':
        new_id = new_id[:-1]
        len_new_id -= 1
    if new_id and new_id[0] == '.':
        new_id = new_id[1:]
        len_new_id -= 1
    # 5. 빈 문자열이라면, new_id에 "a"를 대입한다.
    if not new_id:
        new_id = 'a'
        len_new_id = 1
    # 6. 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거한다.
    # 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거한다.
    if len_new_id >= 16:
        new_id = new_id[:15]
        len_new_id = 15
        if new_id[-1] == '.':
            new_id = new_id[:-1]
            len_new_id -= 1
    # 7. 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while len_new_id < 3:
        new_id += new_id[-1]
        len_new_id += 1

    return new_id