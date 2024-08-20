#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void bfs(int, int, int, int, vector<vector<int>>&, vector<vector<int>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;      cin >> n;
    int m = 0;      cin >> m;
    vector<vector<int>> maps(n, vector<int>(m));
    vector<vector<int>> answers(n, vector<int>(m, 0));
    int start1, start2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maps[i][j];
            if (maps[i][j] == 2) {
                start1 = i;
                start2 = j;
            }
        }
    }

    bfs(n, m, start1, start2, maps, answers);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 1 and answers[i][j] == 0)
                answers[i][j] = -1;
            cout << answers[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


void bfs(int n, int m, int s1, int s2, vector<vector<int>>& arr, vector<vector<int>>& dep) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q;
    q.emplace(s1, s2, 0);
    visited[s1][s2] = true;
    dep[s1][s2] = 0;

    while (!q.empty()) {
        int pos_x = get<0>(q.front());
        int pos_y = get<1>(q.front());
        int pos_dep = get<2>(q.front());
        q.pop();

        for (int p = 0; p < 4; ++p) {
            int npos_x = pos_x + dx[p];
            int npos_y = pos_y + dy[p];
            int npos_dep = pos_dep + 1;
            if (0 <= npos_x and npos_x < n and 0 <= npos_y and npos_y < m) {
                if (!visited[npos_x][npos_y] and arr[npos_x][npos_y] == 1) {
                    q.emplace(npos_x, npos_y, npos_dep);
                    visited[npos_x][npos_y] = true;
                    dep[npos_x][npos_y] = npos_dep;
                }
            }
        }
    }
}