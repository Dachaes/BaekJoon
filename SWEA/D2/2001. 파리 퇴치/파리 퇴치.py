num_test = int(input())
n, m = [0] * num_test, [0] * num_test
space = [[] for _ in range(num_test)]
for i in range(num_test):
    n[i], m[i] = map(int, input().split())
    space_data = []
    for _ in range(n[i]):
        space_data.append(list(map(int, input().split())))
    space[i] = space_data

for k in range(num_test):
    space_size, swatter = n[k], m[k]
    size_catch_fly = space_size - swatter + 1
    catch_fly = [[0] * size_catch_fly for _ in range(size_catch_fly)]
    for i in range(size_catch_fly):
        for j in range(size_catch_fly):
            for o in range(swatter):
                for p in range(swatter):
                    catch_fly[i][j] += space[k][i + o][j + p]

    max_fly = 0
    for i in range(size_catch_fly):
        for j in range(size_catch_fly):
            max_fly = max(max_fly, catch_fly[i][j])
    print(f"#{k + 1} {max_fly}")