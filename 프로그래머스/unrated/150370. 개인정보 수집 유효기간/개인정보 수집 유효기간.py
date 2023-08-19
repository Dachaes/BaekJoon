def solution(today, terms, privacies):
    # today: today 정보
    today = int(today.replace('.', ''))

    # terms_dict: key-약관 종류, value-약관 유효 기간
    terms_dict = {}
    for term in terms:
        terms_dict[term[0]] = int(term[2:])
    
    # expiry_dates: 각 개인 정보(privacy) 에 따른 유효 기간(expiry_date) 을 모두 저장한 리스트
    expiry_dates = []
    # 1. 받은 개인 정보들(privacies) 를 하나하나 확인한다.
    for privacy in privacies:
        # 개인 정보를 보기 편하게 변수 지정
        privacy_y, privacy_m, privacy_d = map(int, [privacy[:4], privacy[5:7], privacy[8:10]])
        privacy_term = privacy[-1]

        expiry_y, expiry_m, expiry_d = privacy_y, privacy_m, privacy_d
        # 2. 개인 정보(privacy) 의 달을 조정한다.
        expiry_m += terms_dict[privacy_term]
        if expiry_m > 12:
            years = expiry_m // 12
            expiry_m %= 12
            if expiry_m == 0:
                expiry_m = 12
                expiry_y -= 1
            expiry_y += years

        # 3. 개인 정보(privacy) 의 일자를 조정한다.
        expiry_d = privacy_d - 1
        if expiry_d == 0:
            expiry_d = 28
            expiry_m -= 1
            if expiry_m == 0:
                expiry_m = 12
                expiry_y -= 1

        # 4. 유효 기간(expiry_date) 를 정리해서 저장한다.
        expiry_date = str(expiry_y)
        if expiry_m < 10:
            expiry_date += '0'
        expiry_date += str(expiry_m)
        if expiry_d < 10:
            expiry_date += '0'
        expiry_date += str(expiry_d)

        expiry_dates.append(int(expiry_date))

    # 5. 개인 정보(privacies)를 모두 모아 정리한 유효 기간 리스트(expiry_dates) 에서
    # 유효하지 않은 개인정보의 번호를 추출한다. -> invaild_privacies
    invalid_privacies = []
    for num_privacy, expiry_date in enumerate(expiry_dates):
        if expiry_date < today:
            invalid_privacies.append(num_privacy + 1)

    return invalid_privacies