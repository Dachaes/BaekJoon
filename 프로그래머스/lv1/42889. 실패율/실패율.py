def solution(N, stages):
    len_stages = len(stages)
    users = []

    for stage in range(1, N + 1):
        cnt = stages.count(stage)
        if cnt == 0:
            users.append([stage, 0])
        else:
            users.append([stage, cnt / len_stages])
        len_stages -= cnt

    users.sort(key=lambda x: (-x[1], x[0]))

    answer = []
    for user in users:
        answer.append(user[0])

    return answer