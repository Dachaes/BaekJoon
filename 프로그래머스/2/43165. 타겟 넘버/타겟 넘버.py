def dfs(n_nums, nums, idx, res, targ, cnt):
    if n_nums == idx:
        if res == targ:
            cnt += 1
        return res, cnt

    res1 = res + nums[idx]
    res1, cnt = dfs(n_nums, nums, idx + 1, res1, targ, cnt)

    res2 = res - nums[idx]
    res2, cnt = dfs(n_nums, nums, idx + 1, res2, targ, cnt)

    return res, cnt


def solution(numbers, target):
    n, count = len(numbers), 0
    result, count = dfs(n, numbers, 0, 0, target, count)

    return count