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

    int n_cities;       cin >> n_cities;
    int n_buses;        cin >> n_buses;

    vector<int> distance(n_cities + 1, INT_MAX);
    vector<vector<pair<int, int>>> graphs(n_cities + 1);
    for (int i = 0; i < n_buses; ++i) {
        int start, end, dist;
        cin >> start >> end >> dist;
        graphs[start].emplace_back(dist, end);
    }
    int start, end;
    cin >> start >> end;

    distance[start] = 0;
    dijkstra(start, graphs, distance);

    cout << distance[end] << '\n';
    return 0;
}


void dijkstra(int start, vector<vector<pair<int, int>>>& graphs, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, start);

    while(!q.empty()) {
        int now_dist = q.top().first;
        int now_pos = q.top().second;
        q.pop();

        // 거리가 멀어서 체크할 필요가 없으면 continue
        if (distance[now_pos] < now_dist)
            continue;

        // 체크
        for (pair<int, int> next : graphs[now_pos]) {
            int next_dist = now_dist + next.first;
            int next_pos = next.second;

            if (next_dist < distance[next_pos]) {
                distance[next_pos] = next_dist;
                q.emplace(next_dist, next_pos);
            }
        }
    }
}