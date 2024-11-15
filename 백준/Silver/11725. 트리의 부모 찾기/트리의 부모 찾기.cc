#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;


vector<int> bfs(int, vector<vector<int>> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;     cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;       cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<int> parent = bfs(n, graph);
    for (int i = 2; i < n + 1; ++i) {
        cout << parent[i] << endl;
    }

    return 0;
}


vector<int> bfs(int n, vector<vector<int>> &graph) {
    vector<int> parent(n + 1, -1);
    parent[1] = 1;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    queue<int> q;
    q.emplace(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (!visited[next]) {
                parent[next] = curr;
                visited[next] = true;
                q.emplace(next);
            }
        }
    }

    return parent;
}