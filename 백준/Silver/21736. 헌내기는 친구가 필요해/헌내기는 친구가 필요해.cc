#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int answer = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void bfs(int, int, int, int, vector<vector<char>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;          cin >> n;
    int m = 0;          cin >> m;

    vector<vector<char>> maps(n, vector<char>(m));
    int doyeon_x = 0, doyeon_y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char map;
            cin >> map;
            maps[i][j] = map;

            if (map == 'I') {
                doyeon_x = i;
                doyeon_y = j;
            }
        }
    }

    bfs(doyeon_x, doyeon_y, n, m, maps);

    if (answer != 0)
        cout << answer << '\n';
    else
        cout << "TT" << '\n';

    return 0;
}


void bfs(int start_x, int start_y, int x, int y, vector<vector<char>>& arr) {
    vector<vector<bool>> visited(x, vector<bool>(y, false));
    queue<pair<int, int>> q;
    q.emplace(start_x, start_y);
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int p = 0; p < 4; ++p) {
            int next_x = now_x + dx[p];
            int next_y = now_y + dy[p];

            if (0 <= next_x and next_x < x and 0 <= next_y and next_y < y) {
                char element = arr[next_x][next_y];
                if (!visited[next_x][next_y] and element != 'X') {
                    q.emplace(next_x, next_y);
                    visited[next_x][next_y] = true;
                    if (element == 'P') {
                        answer++;
                    }
                }
            }

        }
    }
}