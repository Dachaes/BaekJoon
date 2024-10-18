#include <iostream>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes, n_edges;
    cin >> n_vertexes >> n_edges;

    vector<vector<int>> cost(n_vertexes + 1, vector<int>(n_vertexes + 1, INT_MAX));
    for (int i = 0; i < n_vertexes + 1; ++i) {
        cost[i][i] = 0;
    }
    for (int i = 0; i < n_edges; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }
    for (int k = 1; k < n_vertexes + 1; ++k) {
        for (int i = 1; i < n_vertexes + 1; ++i) {
            for (int j = 1; j < n_vertexes + 1; ++j) {
                if (cost[i][k] != INT_MAX and cost[k][j] != INT_MAX)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    // 출력
    for (int i = 1; i < n_vertexes + 1; ++i) {
        for (int j = 1; j < n_vertexes + 1; ++j) {
            if (cost[i][j] != INT_MAX)
                cout << cost[i][j] << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }

    return 0;
}