#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int n, m, answer;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void dfs(int, int, int, int, vector<vector<int>>&, vector<vector<bool>>&);
void poly(int, int, vector<vector<int>>&);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = true;
            dfs(i, j, 2, arr[i][j], arr, visited);
            poly(i, j, arr);
            visited[i][j] = false;
        }
    }

    cout << answer << '\n';

    return 0;
}


void dfs(int x, int y, int dep, int sum, vector<vector<int>>& arr, vector<vector<bool>>& visited) {
    if (dep == 5) {
        answer = max(answer, sum);
        return;
    }

    for (int p = 0; p < 4; ++p) {
        int nx = x + dx[p];
        int ny = y + dy[p];
        if (0 <= nx and nx < n and 0 <= ny and ny < m and !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, dep + 1, sum + arr[nx][ny], arr, visited);
            visited[nx][ny] = false;
        }
    }
}


void poly(int px, int py, vector<vector<int>>& arr) {
    // ㅏ
    int p1_x = px;          int p1_y = py;
    int p2_x = px + 1;      int p2_y = py;
    int p3_x = px + 1;      int p3_y = py + 1;
    int p4_x = px + 2;      int p4_y = py;
    if (p3_x < n and p4_x < n and p3_y < m) {
        answer = max(answer, arr[p1_x][p1_y] + arr[p2_x][p2_y] + arr[p3_x][p3_y] + arr[p4_x][p4_y]);
    }

    // ㅜ
    p1_x = px;              p1_y = py;
    p2_x = px;              p2_y = py + 1;
    p3_x = px;              p3_y = py + 2;
    p4_x = px + 1;          p4_y = py + 1;
    if (p4_x < n and p3_y < m and p4_y < m) {
        answer = max(answer, arr[p1_x][p1_y] + arr[p2_x][p2_y] + arr[p3_x][p3_y] + arr[p4_x][p4_y]);
    }

    // ㅓ
    p1_x = px;              p1_y = py + 1;
    p2_x = px + 1;          p2_y = py;
    p3_x = px + 1;          p3_y = py + 1;
    p4_x = px + 2;          p4_y = py + 1;
    if (p3_x < n and p4_x < n and p4_y < m) {
        answer = max(answer, arr[p1_x][p1_y] + arr[p2_x][p2_y] + arr[p3_x][p3_y] + arr[p4_x][p4_y]);
    }

    // ㅗ
    p1_x = px;              p1_y = py + 1;
    p2_x = px + 1;          p2_y = py;
    p3_x = px + 1;          p3_y = py + 1;
    p4_x = px + 1;          p4_y = py + 2;
    if (p4_x < n and p3_y < m and p4_y < m) {
        answer = max(answer, arr[p1_x][p1_y] + arr[p2_x][p2_y] + arr[p3_x][p3_y] + arr[p4_x][p4_y]);
    }
}