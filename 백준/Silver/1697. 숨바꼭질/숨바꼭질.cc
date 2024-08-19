#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int bfs (int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int pos_subin = 0;      cin >> pos_subin;
    int pos_bro = 0;        cin >> pos_bro;

    if (pos_subin == pos_bro) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = bfs(pos_subin, pos_bro);
    cout << ans << '\n';
    
    return 0;
}


int bfs (int pos, int goal) {
    queue<pair<int, int>> positions;
    vector<bool> visited(100001, false);
    positions.emplace(pos, 0);
    visited[pos] = true;
    int sec = 0;

    while (!positions.empty()) {
        pos = positions.front().first;
        sec = positions.front().second;

        positions.pop();

        int next_pos = pos + 1;
        if (next_pos < 100001 and !visited[next_pos]) {
            if (next_pos == goal)
                return sec + 1;
            positions.emplace(next_pos, sec + 1);
            visited[next_pos] = true;
        }
        next_pos = pos - 1;
        if (0 <= next_pos and next_pos < 100001 and !visited[next_pos]) {
            if (next_pos == goal)
                return sec + 1;
            positions.emplace(next_pos, sec + 1);
            visited[next_pos] = true;
        }
        next_pos = pos * 2;
        if (pos < goal and next_pos < 100001 and !visited[next_pos]) {
            if (next_pos == goal)
                return sec + 1;
            positions.emplace(next_pos, sec + 1);
            visited[next_pos] = true;
        }
    }
}