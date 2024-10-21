#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;


int dijkstra(int, int, vector<vector<pair<int, int>>>&, vector<int>&, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes, n_edges;
    cin >> n_vertexes >> n_edges;

    vector<vector<pair<int, int>>> graphs(n_vertexes + 1);
    vector<int> route_graphs(n_vertexes + 1, -1);
    for (int i = 0; i < n_edges; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        graphs[a].emplace_back(d, b);
        graphs[b].emplace_back(d, a);
    }

    // 원래 거리
    int dist = dijkstra(1, n_vertexes, graphs, route_graphs, 0);
    if (dist == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }

    // 한 개의 길을 막았을 때의 거리
    int dist_obstruct = 0;
    for (int i = 2; i < n_vertexes + 1; ++i) {
        int dist_temp = dijkstra(1, n_vertexes, graphs, route_graphs, i);
        dist_obstruct = max(dist_obstruct, dist_temp);

        if (dist_obstruct == INT_MAX)
            break;
    }

    // 결과
    if (dist_obstruct == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist_obstruct - dist << endl;

    return 0;
}


int dijkstra(int start, int goal, vector<vector<pair<int, int>>> &graphs, vector<int> &route, int obstruct) {
    vector<int> distance(goal + 1, INT_MAX);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    // 최단 루트 탐색 전
    if (obstruct == 0) {
        while(!pq.empty()) {
            int curr_dist = pq.top().first;
            int curr_pos = pq.top().second;
            pq.pop();

            if (distance[curr_pos] < curr_dist)
                continue;

            for (pair<int, int> next : graphs[curr_pos]){
                int next_dist = curr_dist + next.first;
                int next_pos = next.second;

                if (next_dist < distance[next_pos]) {
                    distance[next_pos] = next_dist;
                    pq.emplace(next_dist, next_pos);
                    route[next_pos] = curr_pos;
                }
            }
        }
    }

    // 최단 루트 탐색 후 (루트 하나씩 차단)
    else {
        if (route[obstruct] != -1) {
            while(!pq.empty()) {
                int curr_dist = pq.top().first;
                int curr_pos = pq.top().second;
                pq.pop();

                if (distance[curr_pos] < curr_dist)
                    continue;

                for (pair<int, int> next : graphs[curr_pos]){
                    int next_dist = curr_dist + next.first;
                    int next_pos = next.second;

                    if (curr_pos == route[obstruct] and next_pos == obstruct)
                        continue;

                    if (next_dist < distance[next_pos]) {
                        distance[next_pos] = next_dist;
                        pq.emplace(next_dist, next_pos);
                    }
                }
            }
        }
    }

    return distance[goal];
}