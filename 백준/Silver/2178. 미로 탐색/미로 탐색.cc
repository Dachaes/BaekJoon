#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int answer = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void bfs(int, int, int, int, vector<vector<int>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;          cin >> n;
    int m = 0;          cin >> m;
    cin.ignore();

    vector<vector<int>> maps(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        for (int j = 0; j < m; ++j) {
            maps[i][j] = line[j] - '0';
        }
    }

    bfs(0, 0, n, m, maps);

    cout << answer << '\n';

    return 0;
}


void bfs(int start_x, int start_y, int x, int y, vector<vector<int>>& arr) {
    // 종료 조건
    if (start_x == (x - 1) and start_y == (y - 1)) {
        answer = 1;
        return;
    }

    vector<vector<bool>> visited(x, vector<bool>(y, false));
    queue<tuple<int, int, int>> q;
    q.emplace(start_x, start_y, 1);
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        int now_dep = get<2>(q.front());
        q.pop();

        for (int p = 0; p < 4; ++p) {
            int next_x = now_x + dx[p];
            int next_y = now_y + dy[p];
            int next_dep = now_dep + 1;

            // 종료 조건
            if (next_x == (x - 1) and next_y == (y - 1)) {
                answer = next_dep;
                return;
            }

            if (0 <= next_x and next_x < x and 0 <= next_y and next_y < y) {
                if (arr[next_x][next_y] == 1 and !visited[next_x][next_y]) {

                    q.emplace(next_x, next_y, next_dep);
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
}