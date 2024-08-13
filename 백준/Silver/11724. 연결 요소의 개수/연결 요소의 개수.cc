#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfs(vector<vector<int>>&, vector<bool>&, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_vertexes = 0;        cin >> n_vertexes;
    int n_edges = 0;           cin >> n_edges;
    // 입력 (간선)
    vector<vector<int>> points(n_vertexes + 1, vector<int>(n_vertexes + 1));
    vector<bool> visited(n_vertexes + 1, false);
    for (int i = 0; i < n_edges; ++i) {
        int a, b;
        cin >> a >> b;
        points[a][b] = 1;
        points[b][a] = 1;
    }

    int answer = 0;
    for (int i = 1; i <= n_vertexes; ++i) {
        if (!visited[i]) {
            bfs(points, visited, i);
            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}


void bfs(vector<vector<int>>& points, vector<bool>& visited, int start) {
    queue<int> q;
    q.emplace(start);
    visited[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next = 1; next < visited.size(); ++next) {
            if (now == next)
                continue;
            if (!visited[next] and points[now][next]) {
                q.emplace(next);
                visited[next] = true;
            }
        }
    }
}