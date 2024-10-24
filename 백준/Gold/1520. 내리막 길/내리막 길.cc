#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dfs(int, int, int, int, vector<vector<int>> &, vector<vector<int>> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;      cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;        cin >> num;
            arr[i][j] = num;
        }
    }
    
    int answer = dfs(0, 0, n, m, arr, dp);
    cout << answer << endl;
    
    return 0;
}


int dfs(int x, int y, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    // 목표 지점 도달했다면
    if (x == n - 1 and y == m - 1)
        return 1;

    // 이미 와 본 적 있는 곳이라면
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    // 이외
    dp[x][y] = 0;
    for (int p = 0; p < 4; ++p) {
        int nx = x + dx[p];
        int ny = y + dy[p];
        if (0 <= nx and nx < n and 0 <= ny and ny < m) {
            if (arr[x][y] > arr[nx][ny]) {
                dp[x][y] += dfs(nx, ny, n, m, arr, dp);
            }
        }
    }
    return dp[x][y];
}