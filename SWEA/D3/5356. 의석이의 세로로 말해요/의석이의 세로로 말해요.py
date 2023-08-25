n_tests = int(input())

for t in range(1, n_tests + 1):
    n_letters = 0
    letters_arr = []
    for _ in range(5):
        letters = list(input())
        n_letters += len(letters)
        letters_arr.append(letters)

    reading, n_reading = '', 0

    while n_letters != n_reading:
        for letters_list in letters_arr:
            if letters_list:
                letter = letters_list.pop(0)
                reading += letter
                n_reading += 1

    print(f"#{t}", reading)