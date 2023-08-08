from copy import deepcopy

n_tests = 10

for t in range(1, n_tests + 1):
    len_word = int(input())
    random_words = [list(input().split()[0]) for _ in range(8)]
    # random_words 의 전치행렬
    random_words_T = deepcopy(random_words)
    for i in range(8):
        for j in range(8):
            if i > j:
                random_words_T[i][j], random_words_T[j][i] = random_words_T[j][i], random_words_T[i][j]

    count = 0
    # 1. 가로행 확인
    for random_word in random_words:
        for idx in range(0, 8 - len_word + 1):
            if random_word[idx:idx+len_word] == random_word[idx:idx+len_word][::-1]:
                count += 1

    # 2. 세로열 확인
    for random_word in random_words_T:
        for idx in range(0, 8 - len_word + 1):
            if random_word[idx:idx+len_word] == random_word[idx:idx+len_word][::-1]:
                count += 1

    print(f"#{t}", count)