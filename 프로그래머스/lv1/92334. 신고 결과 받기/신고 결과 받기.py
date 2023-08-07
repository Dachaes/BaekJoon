def solution(id_list, reports, k):
    # reported_users: 유저의 신고(당한) 정보가 저장된 딕셔너리
    # -> key: 해당유저, value: 해당 유저를 신고한 유저 리스트
    reported_users = {user: [] for user in id_list}
    # users_to_receive_mail: 받을 메일의 개수가 저장된 딕셔너리
    users_to_receive_mail = {user: 0 for user in id_list}

    # 1. 신고 정보 리스트(reports) 를 보고, 유저의 신고 정보 딕셔너리(reported_users) 에 나눠서 저장
    for report in reports:
        by_another_user, reported_user = report.split()
        if by_another_user not in reported_users.get(reported_user):
            reported_users[reported_user].append(by_another_user)
    # print(reported_users)

    disallowed_users = []       # disallowed_users: 사이트 이용이 정지된 유저 리스트
    # 2. reported_users 를 보고 일정 신고 횟수(k) 이상인 경우 사이트 이용을 정지한다.
    for reported_user, by_another_user in reported_users.items():
        if len(by_another_user) >= k:
            disallowed_users.append(reported_user)
    # print(disallowed_users)

    # 3. 이용이 정지된 유저들을 신고한 유저를 확인한다.
    for disallowed_user in disallowed_users:
        for reported_user, by_another_user in reported_users.items():
            # 3-1. 정지된 유저와 신고당한 유저가 같다면, 해당 유저를 신고한 유저의 users_to_receive_mail 를 증가한다.
            if disallowed_user == reported_user:
                for user in by_another_user:
                    users_to_receive_mail[user] += 1
    # print(users_to_receive_mail)


    answer = list(users_to_receive_mail.values())
    return answer