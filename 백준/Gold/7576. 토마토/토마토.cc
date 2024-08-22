#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int answer = 0;
int n_ripe_tomatoes = 0, n_unripe_tomatoes = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0,0};
void bfs(int, int, vector<vector<int>>&, queue<tuple<int, int, int>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;      cin >> n;
    int m = 0;      cin >> m;

    vector<vector<int>> tomatoes(m, vector<int>(n));
    queue<tuple<int, int, int>> q_tomatoes;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int tomato;
            cin >> tomato;
            tomatoes[i][j] = tomato;

            if (tomato == 1) {
                n_ripe_tomatoes++;
                q_tomatoes.emplace(i, j, 0);
            }
            else if (tomato == 0)
                n_unripe_tomatoes++;
        }
    }

    // 안익은 토마토가 있으면 bfs
    if (n_unripe_tomatoes != 0)
        bfs(m, n, tomatoes, q_tomatoes);

    // bfs 하고 모든 토마토가 익었으면 얼마나 걸렸는지 출력, 아니면 -1 출력
    if (n_unripe_tomatoes == 0)
        cout << answer << '\n';
    else
        cout << -1 << '\n';

    return 0;
}


void bfs(int x, int y, vector<vector<int>>& arr, queue<tuple<int, int, int>>& q) {
    while (!q.empty()) {
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        int now_dep = get<2>(q.front());
        q.pop();

        int next_dep = now_dep + 1;
        for (int p = 0; p < 4; ++p) {
            int next_x = now_x + dx[p];
            int next_y = now_y + dy[p];

            if (0 <= next_x and next_x < x and 0 <= next_y and next_y < y) {
                if (arr[next_x][next_y] == 0) {
                    arr[next_x][next_y] = 1;
                    q.emplace(next_x, next_y, next_dep);
                    n_unripe_tomatoes--;
                    n_ripe_tomatoes++;
                    answer = next_dep;
                }
            }
        }
    }
}