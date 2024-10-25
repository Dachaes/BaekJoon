#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;      cin >> tc;
    while (tc--) {
        int n_files;        cin >> n_files;
        vector<int> prefix_sum(n_files + 1, 0);
        vector<vector<int>> dp(n_files, vector<int>(n_files, INT_MAX));
        for (int i = 0; i < n_files; ++i) {
            int file;       cin >> file;
            prefix_sum[i + 1] = prefix_sum[i] + file;
            dp[i][i] = 0;
        }

        for (int i = n_files; i >= 0; --i) {
            for (int j = i; j < n_files; ++j) {
                for (int k = i; k <= j - 1; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix_sum[j + 1] - prefix_sum[i]);
                }
            }
        }

        cout << dp[0][n_files - 1] << endl;
    }
    return 0;
}