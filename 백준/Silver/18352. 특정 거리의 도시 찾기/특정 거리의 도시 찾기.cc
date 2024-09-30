#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes, n_graphs, goal_dist, start;
    cin >> n_vertexes >> n_graphs >> goal_dist >> start;

    vector<vector<int>> graphs(n_vertexes + 1);
    for (int i = 0; i < n_graphs; ++i) {
        int a, b;
        cin >> a >> b;
        graphs[a].emplace_back(b);
    }

    vector<int> answer;
    // bfs
    queue<pair<int, int>> q;
    q.emplace(0, start);
    vector<bool> visited(n_vertexes + 1, false);
    visited[start] = true;
    while (!q.empty()) {
        int curr_dist = q.front().first;
        int curr_pos = q.front().second;
        q.pop();

        for (int next : graphs[curr_pos]) {
            if (!visited[next]) {
                visited[next] = true;

                if (curr_dist + 1 == goal_dist)
                    answer.emplace_back(next);
                else
                    q.emplace(curr_dist + 1, next);
            }
        }
    }

    // 출력
    if (answer.empty())
        cout << -1 << '\n';
    else {
        sort(answer.begin(), answer.end());
        for (int ans : answer)
            cout << ans << '\n';
    }

    return 0;
}