#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


long long dijkstra(int, int, vector<vector<pair<int, int>>>&, vector<int>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes;     cin >> n_vertexes;
    int n_edges;       cin >> n_edges;
    vector<int> visible(n_vertexes, 0);
    vector<vector<pair<int, int>>> graph(n_vertexes);
    for (int i = 0; i < n_vertexes; ++i) {
        cin >> visible[i];
    }
    for (int i = 0; i < n_edges; ++i) {
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        graph[v1].emplace_back(d, v2);
        graph[v2].emplace_back(d, v1);
    }

    long long answer = dijkstra(0, n_vertexes, graph, visible);

    cout << answer << '\n';

    return 0;
}


long long dijkstra(int start, int size, vector<vector<pair<int, int>>>& graph, vector<int>& visible) {
    vector<long long> distance(size, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    distance[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        long long now_dist = pq.top().first;
        int now_pos = pq.top().second;
        pq.pop();

        if (distance[now_pos] < now_dist)
            continue;

        for (pair<int, int> next : graph[now_pos]) {
            long long next_dist = now_dist + next.first;
            int next_pos = next.second;

            if (next_pos == 0 or next_pos == size - 1 or visible[next_pos] == 0) {
                if (next_dist < distance[next_pos]) {
                    distance[next_pos] = next_dist;
                    pq.emplace(next_dist, next_pos);
                }
            }
        }
    }

    if (distance[size - 1] == LLONG_MAX)
        return -1;
    else
        return distance[size - 1];
}