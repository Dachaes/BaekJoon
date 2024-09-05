#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1,0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // m: 가로, n: 세로, h: 높이
    int n, m, h;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> tomato_3(h, vector<vector<int>>(n, vector<int>(m)));
    queue<tuple<int, int, int, int>> tomato_q;
    int n_unripe = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int tomato;
                cin >> tomato;
                tomato_3[i][j][k] = tomato;

                // 익은 상태면 위치를 큐에 저장, 안 익은 상태면 개수 카운팅
                if (tomato == 1)
                    tomato_q.emplace(k, j, i, 0);
                else if (tomato == 0)
                    n_unripe++;
            }
        }
    }

    // bfs
    int answer = 0;
    while (!tomato_q.empty()) {
        int curr_x = get<0>(tomato_q.front());
        int curr_y = get<1>(tomato_q.front());
        int curr_z = get<2>(tomato_q.front());
        int curr_t = get<3>(tomato_q.front());
        tomato_q.pop();

        for (int p = 0; p < 6; p++) {
            int next_x = curr_x + dx[p];
            int next_y = curr_y + dy[p];
            int next_z = curr_z + dz[p];
            if (0 <= next_x and next_x < m and 0 <= next_y and next_y < n and 0 <= next_z and next_z < h) {
                if (tomato_3[next_z][next_y][next_x] == 0) {
                    tomato_q.emplace(next_x, next_y, next_z, curr_t + 1);
                    tomato_3[next_z][next_y][next_x] = 1;
                    n_unripe--;
                    answer = curr_t + 1;
                }
            }
        }
    }

    if (n_unripe == 0)
        cout << answer << '\n';
    else
        cout << -1 << '\n';

    return 0;
}