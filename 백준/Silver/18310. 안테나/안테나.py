# BOJ_18310 : 안테나

# Input
num = int(input())
houses = list(map(int, input().split()))
houses.sort()

cnt = 0
res = [-1, 0]           # [위치, 합]
sum_house = sum(houses)
for house in houses:
    temp = sum_house - (house * (num - cnt)) + (house * cnt)
    if res[0] == -1 or temp < res[1]:
        res[0] = house
        res[1] = temp
    sum_house -= (house * 2)
    cnt += 1

print(res[0])