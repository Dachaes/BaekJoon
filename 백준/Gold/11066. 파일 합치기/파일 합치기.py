# BOJ_11066 : 파일 합치기
# https://velog.io/@seung_min/%EB%B0%B1%EC%A4%80%ED%8C%8C%EC%9D%B4%EC%8D%AC-11066%EB%B2%88-%ED%8C%8C%EC%9D%BC-%ED%95%A9%EC%B9%98%EA%B8%B0
import sys
input = sys.stdin.readline

tests_ = int(input())
for t in range(1, tests_ + 1):
    files_ = int(input())
    files = [0] + list(map(int, input().split()))

    dp = [[0] * (files_ + 1) for _ in range(files_ + 1)]

    # for i in range(1, files_ + 1):
    #     for j in range(1, files_ + 1):
    #         if i + 1 == j:
    #             dp[i][j] = files[i] + files[j]

    for i in range(files_ - 1, 0, -1):
        for j in range(i, files_ + 1):
            if i + 1 == j:
                dp[i][j] = files[i] + files[j]
            elif i < j and dp[i][j] == 0:
                dp[i][j] = min([dp[i][k] + dp[k + 1][j] for k in range(i, j)]) + sum(files[i:j + 1])
    
    print(dp[1][files_])