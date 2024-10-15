#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool flag_bipartite_graph = true;
void bfs(int, int, vector<vector<int>> &, vector<int> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n_tests;
    cin >> n_tests;

    for (int t = 0; t < n_tests; ++t) {
        int n_vertexes, n_edges;
        cin >> n_vertexes >> n_edges;

        // 그래프 채우기
        vector<vector<int>> graphs(n_vertexes + 1);
        for (int i = 0; i < n_edges; ++i) {
            int a, b;
            cin >> a >> b;
            graphs[a].emplace_back(b);
            graphs[b].emplace_back(a);
        }

        // 이분 그래프 체크
        flag_bipartite_graph = true;
        vector<int> colors(n_vertexes + 1, 0);
        for (int i = 1; i <= n_vertexes; ++i) {
            if (colors[i] == 0)
                bfs(n_vertexes, i, graphs, colors);
            if (!flag_bipartite_graph) {
                cout << "NO" << '\n';
                break;
            }
        }

        if (flag_bipartite_graph)
            cout << "YES" << '\n';
    }

    return 0;
}


void bfs(int n, int start, vector<vector<int>> &graphs, vector<int> &colors) {
    queue<int> q;
    q.emplace(start);
    colors[start] = -1;

    while (!q.empty()) {
        int curr = q.front();
        int color = colors[curr];
        q.pop();

        for (int next : graphs[curr]) {
            // 이분 그래프가 아닌 경우
            if (colors[next] == color) {
                flag_bipartite_graph = false;
                return;
            }
            
            if (colors[next] == 0) {
                q.emplace(next);
                colors[next] = color * -1;
            }
        }
    }
}