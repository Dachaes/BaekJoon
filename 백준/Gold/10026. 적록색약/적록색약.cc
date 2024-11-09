#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs_general(int, int, int, vector<vector<char>> &, vector<vector<bool>> &);
void bfs_blindness(int, int, int, vector<vector<char>> &, vector<vector<bool>> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;      cin >> n;
    vector<vector<char>> colors(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> colors[i][j];
        }
    }

    int answer_g = 0, answer_b = 0;
    vector<vector<bool>> visited_g(n, vector<bool>(n, false));
    vector<vector<bool>> visited_b(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited_g[i][j]) {
                bfs_general(i, j, n, colors, visited_g);
                answer_g++;
            }
            if (!visited_b[i][j]) {
                bfs_blindness(i, j, n, colors, visited_b);
                answer_b++;
            }
        }
    }

    cout << answer_g << ' ' << answer_b << endl;

    return 0;
}


void bfs_general(int x, int y, int n, vector<vector<char>> &colors, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.emplace(x, y);
    char color = colors[x][y];

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && colors[nx][ny] == color) {
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}


void bfs_blindness(int x, int y, int n, vector<vector<char>> &colors, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.emplace(x, y);
    char color = colors[x][y];

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
                if (colors[nx][ny] == color
                    || (colors[nx][ny] == 'R' && color == 'G')
                    || (colors[nx][ny] == 'G' && color == 'R')) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}