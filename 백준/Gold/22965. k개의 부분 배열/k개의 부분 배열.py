# BOJ_22965 : k개의 부분 배열
def check_order(list_):
    min_ = min(list_)
    max_ = max(list_)
    sorted_list = sorted(list_)
    new_list = []
    # 1
    if list_ == sorted_list:
        return 1
    # 2, 3
    start_to_insert = False
    for i in range(0, N):
        if list_[i] == min_:
            start_to_insert = True
        if start_to_insert:
            new_list.append(list_[i])
    for i in range(0, N):
        if start_to_insert:
            new_list.append(list_[i])
        if list_[i] == max_:
            start_to_insert = False
    if new_list == sorted_list:
        return 2
    else:
        return 3


N = int(input())
A = list(map(int, input().split(' ')))
k = check_order(A)
print(k)
