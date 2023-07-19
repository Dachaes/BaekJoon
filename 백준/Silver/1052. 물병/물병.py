# BOJ_1052 : 물병

# Input
n, k = map(int, input().split())

bin_n = list(map(int, bin(n)[2:]))[::-1]
num_bottles = bin_n.count(1)

buy_bottles = 0
while k < num_bottles:
    new_bottles = pow(2, bin_n.index(1))
    buy_bottles += new_bottles

    n = n + new_bottles
    bin_n = list(map(int, bin(n)[2:]))[::-1]
    num_bottles = bin_n.count(1)

print(buy_bottles)