#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;          cin >> n;

    // DP
    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        int min_value = INT_MAX;
        for (int j = 1; j * j <= i; ++j) {
            int small_number = i - j * j;
            min_value = min(dp[small_number] + 1, min_value);
        }
        dp[i] = min_value;
    }

    cout << dp[n] << '\n';
    return 0;
}