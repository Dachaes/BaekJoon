def solution(surveys, choices):
    n = len(surveys)
    types = {'R': 0, 'T': 0, 'C': 0, 'F': 0,
             'J': 0, 'M': 0, 'A': 0, 'N': 0}
    my_type = ['T', 'F', 'M', 'N']

    for idx in range(n):
        survey_type1, survey_type2 = surveys[idx][0], surveys[idx][1]
        choice = choices[idx]
        
        # 1. survey 타입에 따라 해당 캐릭터의 타입 점수를 올린다.
        if 1 <= choice < 4:
            types[survey_type1] += (4 - choice)
        elif 4 < choice <= 7:
            types[survey_type2] += (choice - 4)

    # 2. 생성해둔 my_type 을 survey 값에 따라 변경한다.
    # 2-1. R과 T 비교
    if types['R'] >= types['T']:
        my_type[0] = 'R'
    # 2-2. C와 F 비교
    if types['C'] >= types['F']:
        my_type[1] = 'C'
    # 2-3. J와 M 비교
    if types['J'] >= types['M']:
        my_type[2] = 'J'
    # 2-4. A와 N 비교
    if types['A'] >= types['N']:
        my_type[3] = 'A'

    my_type = ''.join(my_type)
    
    return my_type