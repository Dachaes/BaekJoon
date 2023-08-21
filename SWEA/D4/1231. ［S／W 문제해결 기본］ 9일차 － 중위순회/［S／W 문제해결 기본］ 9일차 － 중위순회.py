def inorder(node):
    global result
    if node:
        inorder(children1[node])
        result += tree[node]
        inorder(children2[node])


n_tests = 10

for t in range(1, n_tests + 1):
    n_nodes = int(input())
    tree = [0] * (n_nodes + 1)

    children1 = [0] * (n_nodes + 1)
    children2 = [0] * (n_nodes + 1)
    for _ in range(n_nodes):
        data = list(input().split())
        n_data = len(data)

        tree[int(data[0])] = data[1]
        if n_data >= 3:
            children1[int(data[0])] = int(data[2])
        if n_data == 4:
            children2[int(data[0])] = int(data[3])

    result = ''
    inorder(1)

    print(f"#{t}", result)
