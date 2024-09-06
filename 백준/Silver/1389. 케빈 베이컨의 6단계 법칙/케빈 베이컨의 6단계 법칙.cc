#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_users, n_graphs;
    cin >> n_users >> n_graphs;

    vector<vector<int>> dist(n_users + 1, vector<int>(n_users + 1, INT_MAX));
    for (int i = 0; i < n_graphs; ++i) {
        int user1, user2;
        cin >> user1 >> user2;
        dist[user1][user2] = 1;
        dist[user2][user1] = 1;
    }

    // 플로이드-워셜
    for (int i = 1; i <= n_users; ++i) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n_users; ++k) {
        for (int i = 1; i <= n_users; ++i) {
            for (int j = 1; j <= n_users; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<int> kevin_bacon(n_users + 1, 0);
    for (int i = 1; i <= n_users; ++i) {
        for (int j = 1; j <= n_users; ++j) {
            kevin_bacon[i] += dist[i][j];
        }
    }

    int answer = min_element(kevin_bacon.begin() + 1, kevin_bacon.end()) - kevin_bacon.begin();
    cout << answer << '\n';
    return 0;
}