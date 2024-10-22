#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;


int dx[4] = {-1, 1, 0,0};
int dy[4] = {0, 0, -1,1};
int dijkstra(int, vector<vector<int>> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc = 1;
    int n;      cin >> n;
    while (n != 0) {
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;      cin >> x;
                arr[i][j] = x;
            }
        }

        int dist = dijkstra(n, arr);

        cout << "Problem " << tc << ": " << dist << endl;
        tc++;
        cin >> n;
    }

    return 0;
}


int dijkstra(int n, vector<vector<int>> &graph) {
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    distance[0][0] = graph[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.emplace(graph[0][0], make_pair(0, 0));

    while(!pq.empty()) {
        // current 위치 확인
        int curr_dist = pq.top().first;
        pair<int, int> curr_pos = pq.top().second;
        pq.pop();

        if (distance[curr_pos.first][curr_pos.second] < curr_dist)
            continue;

        // next 위치 확인
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next_pos = {curr_pos.first + dx[i], curr_pos.second + dy[i]};

            // 범위 외인 경우는 continue
            if (!(0 <= next_pos.first and next_pos.first < n and 0 <= next_pos.second and next_pos.second < n))
                continue;

            int next_dist = curr_dist + graph[next_pos.first][next_pos.second];

            if (next_dist < distance[next_pos.first][next_pos.second]) {
                distance[next_pos.first][next_pos.second] = next_dist;
                pq.emplace(next_dist, next_pos);
            }
        }
    }

    return distance[n - 1][n - 1];
}