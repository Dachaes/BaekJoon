#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfs(int, int, int, int, vector<vector<int>>&);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1 (테스트 케이스 개수)
    int n_tests = 0;
    cin >> n_tests;

    // 입력 2 (밭의 크기, 배추의 개수)
    int m = 0, n = 0, n_cabbages = 0;
    for (int n_test = 0; n_test < n_tests; ++n_test) {
        cin >> m >> n >> n_cabbages;

        // 입력 3 (배추의 위치 + 체크도 겸함)
        vector<vector<int>> field(m, vector<int>(n, 0));

        // 빈 밭에 배추를 채우기
        int x = 0, y = 0;
        for (int i = 0; i < n_cabbages; ++i) {
            cin >> x >> y;
            field[x][y] = 1;
        }

        int worms = 0;
        // 양배추가 있고, 아직 확인되지 않은 구간 찾기
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (field[i][j]) {
                    // 이 구간을 기준으로 bfs 탐색
                    bfs(i, j, m, n, field);
                    worms++;
                }
            }
        }

        cout << worms << '\n';
    }

    return 0;
}


// 배추흰지렁이를 카운트하는 함수 (bfs)
void bfs(int x, int y, int m, int n, vector<vector<int>>& ground) {
    queue<pair<int, int>> q;
    ground[x][y] = 0;
    q.emplace(x, y);

    while (!q.empty()) {
        // 현 위치 체크
        x = q.front().first, y = q.front().second;
        q.pop();
        ground[x][y] = 0;

        // 상하좌우 체크
        for (int i = 0; i < 4; ++i) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (0 <= next_x and next_x < m and 0 <= next_y and next_y < n) {
                if (ground[next_x][next_y]) {
                    ground[next_x][next_y] = 0;
                    q.emplace(next_x, next_y);
                }
            }
        }
    }
}