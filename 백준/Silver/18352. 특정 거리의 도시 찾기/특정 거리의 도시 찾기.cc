#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes, n_graphs, dist, start;
    cin >> n_vertexes >> n_graphs >> dist >> start;

    vector<vector<pair<int, int>>> graphs(n_vertexes + 1);
    for (int i = 0; i < n_graphs; ++i) {
        int a, b;
        cin >> a >> b;
        graphs[a].emplace_back(1, b);
    }

    vector<int> distance(n_vertexes + 1, INT_MAX);

    // dijkstra
    queue<pair<int, int>> q;
    q.emplace(0, start);
    distance[start] = 0;
    while (!q.empty()) {
        int curr_dist = q.front().first;
        int curr_pos = q.front().second;
        q.pop();

        if (distance[curr_pos] < curr_dist)
            continue;

        for (pair<int, int> next : graphs[curr_pos]) {
            int next_dist = curr_dist + next.first;
            int next_pos = next.second;

            if (next_dist <= distance[next_pos]) {
                distance[next_pos] = next_dist;
                q.emplace(next_dist, next_pos);
            }
        }
    }

    // 출력
    bool flag_no_answer = true;
    for (int i = 1; i <= n_vertexes; ++i) {
        if (distance[i] == dist) {
            flag_no_answer = false;
            cout << i << '\n';
        }
    }
    if (flag_no_answer)
        cout << -1 << '\n';

    return 0;
}