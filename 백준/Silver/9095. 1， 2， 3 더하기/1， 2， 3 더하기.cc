#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n_tests = 0;
    cin >> n_tests;

    // 입력 2 + 테스트 케이스 계산
    vector<int> dp(12, -1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int max_number = 3;
    for (int t = 0; t < n_tests; ++t) {
        int number = 0;
        cin >> number;

        if (dp[number] != -1) {
            cout << dp[number] << '\n';
            continue;
        }
        else {
            for (int i = max_number + 1; i <= number; ++i) {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
            cout << dp[number] << '\n';
            max_number = number;
        }
    }

    return 0;
}