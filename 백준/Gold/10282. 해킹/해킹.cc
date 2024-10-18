#include <iostream>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;


pair<int, int> dijkstra(int, int, vector<vector<pair<int, int>>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_tests;
    cin >> n_tests;

    for (int t = 0; t < n_tests; ++t) {
        int n_vertexes, n_edges, start;
        cin >> n_vertexes >> n_edges >> start;

        vector<vector<pair<int, int>>> graphs(n_vertexes + 1);
        for (int i = 0; i < n_edges; ++i) {
            int a, b, dist;
            cin >> a >> b >> dist;
            graphs[b].emplace_back(dist, a);
        }

        pair<int, int> result = dijkstra(start, n_vertexes, graphs);

        cout << result.first << ' ' << result.second << endl;
    }

    return 0;
}


pair<int, int> dijkstra(int start, int n, vector<vector<pair<int, int>>> &graphs) {
    pair<int, int> result = {0, 0};

    vector<int> distance(n + 1, INT_MAX);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_pos = pq.top().second;
        pq.pop();

        if (distance[curr_pos] < curr_dist)
            continue;

        for (pair<int, int> next : graphs[curr_pos]) {
            int next_dist = curr_dist + next.first;
            int next_pos = next.second;
            if (next_dist < distance[next_pos]) {
                distance[next_pos] = next_dist;
                pq.emplace(next_dist, next_pos);
            }
        }
    }

    for (int d : distance) {
        if (d != INT_MAX) {
            result.first++;
            result.second = max(result.second, d);
        }
    }

    return result;
}