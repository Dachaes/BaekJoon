n_tests = 10
 
for t in range(1, n_tests + 1):
    n_test = int(input())
    pattern = input()
    text = input()
    len_pattern, len_text = len(pattern), len(text)
 
    count = 0
    i, j = 0, 0
    while i < len_text:
        if text[i] != pattern[j]:
            i = i - j
            j = -1
        i += 1
        j += 1
        if j == len_pattern:
            count += 1
            j = 0
 
    print(f"#{t}", count)