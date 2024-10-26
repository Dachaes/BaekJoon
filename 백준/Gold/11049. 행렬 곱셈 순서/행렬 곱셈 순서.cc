#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n_matrix;        cin >> n_matrix;
    vector<pair<int, int>> matrix(n_matrix, {0, 0});
    vector<vector<int>> dp(n_matrix, vector<int>(n_matrix, INT_MAX));
    for (int i = 0; i < n_matrix; ++i) {
        int x, y;       cin >> x >> y;
        matrix[i] = {x, y};
        dp[i][i] = 0;
    }

    for (int i = n_matrix - 1; i >= 0; --i) {
        for (int j = i; j < n_matrix; ++j) {
            for (int k = i; k <= j - 1; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second);
            }
        }
    }
    
    cout << dp[0][n_matrix - 1] << endl;

    return 0;
}