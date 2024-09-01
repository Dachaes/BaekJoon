#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


void dijkstra(int, vector<vector<pair<int, int>>>&, vector<int>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n_vertexes;     cin >> n_vertexes;
    int n_edges;        cin >> n_edges;
    int goal = n_vertexes;
    vector<vector<pair<int, int>>> graph(n_vertexes + 1);
    for (int i = 0; i < n_edges; ++i) {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].emplace_back(d, e);
        graph[e].emplace_back(d, s);
    }

    // 데이크스트라
    vector<int> distance(n_vertexes + 1, INT_MAX);
    dijkstra(1, graph, distance);

    cout << distance[goal] << '\n';

    return 0;
}


void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, start);

    while (!q.empty()) {
        int now_dist = q.top().first;
        int now_pos = q.top().second;
        q.pop();

        if (distance[now_pos] < now_dist)
            continue;

        for (pair<int, int> next : graph[now_pos]) {
            int next_dist = now_dist + next.first;
            int next_pos = next.second;

            if (next_dist < distance[next_pos]) {
                distance[next_pos] = next_dist;
                q.emplace(next_dist, next_pos);
            }
        }
    }
}