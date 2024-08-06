#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n_computers = 0, n_networks = 0;
    cin >> n_computers >> n_networks;
    // 입력 2
    vector<vector<bool>> virus(n_computers + 1, vector<bool>( n_computers + 1, false));
    vector<bool> checks(n_computers + 1, false);
    for (int i = 0; i < n_networks; ++i) {
        int computer1 = 0, computer2 = 0;
        cin >> computer1 >> computer2;
        virus[computer1][computer2] = true;
        virus[computer2][computer1] = true;
    }

    // 1번과 연결된 컴퓨터 찾기 (bfs)
    queue<int> q;
    q.emplace(1);
    checks[1] = true;

    int count = 0;
    while (!q.empty()) {
        int now_computer = q.front();
        q.pop();

        for (int i = 1; i < n_computers + 1; ++i) {
            if (virus[now_computer][i] and !checks[i]) {
                checks[i] = true;
                q.emplace(i);
                count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}