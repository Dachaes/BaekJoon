from itertools import permutations
def solution(n, weak, friends):
    len_weak = len(weak)
    num_friends = len(friends)

    extended_weak = []
    for i in range(2 * len_weak):
        if i < len_weak:
            extended_weak.append(weak[i])
        else:
            extended_weak.append(weak[i - len_weak] + n)

    friends_groups = list(permutations(friends))

    # 1. 시작 지점을 처음부터 전체 레스토랑의 크기만큼 전부 체크한다. (0 ~ n-1)
    answers = []
    for start in range(len_weak):
        # 2. 친구가 출발 지점부터 어디까지 체크할 수 있는지 확인한다. (pos)
        for friends_group in friends_groups:
            count = 1
            pos1 = extended_weak[start]
            pos2 = pos1 + friends_group[count - 1]
            for index in range(start, start + len_weak):
                if pos2 < extended_weak[index]:
                    count += 1
                    if num_friends < count:
                        break
                    pos2 = extended_weak[index] + friends_group[count - 1]
            answers.append(count)

    answer = -1
    if answers:
        answer = min(answers)
    return answer