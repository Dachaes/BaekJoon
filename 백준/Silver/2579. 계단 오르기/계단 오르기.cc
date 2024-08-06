#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n_stairs = 0;
    cin >> n_stairs;

    // 입력 2
    vector<int> stairs(n_stairs);
    vector<int> dp(n_stairs);
    for (int i = 0; i < n_stairs; ++i)
        cin >> stairs[i];

    // dp 초기화
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    // 다이나믹 프로그래밍
    int a = 0, b = 0, c = 0;
    for (int i = 3; i < n_stairs; ++i) {
        a = stairs[i] + stairs[i - 1] + dp[i - 3];
        b = stairs[i] + dp[i - 2];

        dp[i] = max(a, b);
    }

    cout << dp[n_stairs - 1] << '\n';
    return 0;
}