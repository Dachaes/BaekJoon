#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


void dijkstra(int, vector<vector<pair<int, int>>>&, vector<int>&);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes;     cin >> n_vertexes;
    int n_graphs;       cin >> n_graphs;
    vector<vector<pair<int, int>>> graph(n_vertexes + 1);
    for (int i = 0; i < n_graphs; ++i) {
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        graph[v1].emplace_back(d, v2);
        graph[v2].emplace_back(d, v1);
    }
    int v1;          cin >> v1;
    int v2;          cin >> v2;

    vector<int> distance_s(n_vertexes + 1, INT_MAX);
    vector<int> distance_v1(n_vertexes + 1, INT_MAX);
    vector<int> distance_v2(n_vertexes + 1, INT_MAX);
    dijkstra(1, graph, distance_s);
    dijkstra(v1, graph, distance_v1);
    dijkstra(v2, graph, distance_v2);

    // 1 -> v1 -> v2 -> n
    int answer1 = INT_MAX;
    int route_s = distance_s[v1];
    int route_v1 = distance_v1[v2];
    int route_v2 = distance_v2[n_vertexes];
    if (route_s != INT_MAX and route_v1 != INT_MAX and route_v2 != INT_MAX)
        answer1 = route_s + route_v1 + route_v2;

    // 1 -> v2 -> v1 -> n
    int answer2 = INT_MAX;
    route_s = distance_s[v2];
    route_v2 = distance_v2[v1];
    route_v1 = distance_v1[n_vertexes];
    if (route_s != INT_MAX and route_v1 != INT_MAX and route_v2 != INT_MAX)
        answer2 = route_s + route_v2 + route_v1;
    
    // 출력
    if (answer1 == INT_MAX and answer2 == INT_MAX)
        cout << -1 << '\n';
    else
        cout << min(answer1, answer2) << '\n';

    return 0;
}


void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    distance[start] = 0;
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