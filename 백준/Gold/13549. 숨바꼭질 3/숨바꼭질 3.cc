#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;


int dx[3] = {-1, 1, 2};
int dijkstra(int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int start, goal;
    cin >> start >> goal;

    int dist = dijkstra(start, goal);

    cout << dist << endl;
    return 0;
}


int dijkstra(int start, int goal) {
    vector<int> distance(100001, INT_MAX);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while(!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_pos = pq.top().second;
        pq.pop();

        if (distance[curr_pos] < curr_dist)
            continue;

        for (int i = 0; i < 3; ++i) {
            int next_dist, next_pos;
            if (i == 2) {
                next_dist = curr_dist;
                next_pos = curr_pos * dx[i];
            }
            else {
                next_dist = curr_dist + 1;
                 next_pos = curr_pos + dx[i];
            }

            if (0 <= next_pos and next_pos <= 100000 and next_dist < distance[next_pos]) {
                distance[next_pos] = next_dist;
                pq.emplace(next_dist, next_pos);
            }
        }
    }

    return distance[goal];
}