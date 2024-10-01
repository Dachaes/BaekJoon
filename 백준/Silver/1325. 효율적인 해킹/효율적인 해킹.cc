#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int bfs(int, int, vector<vector<int>> &);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_vertexes, n_graphs;
    cin >> n_vertexes >> n_graphs;

    vector<vector<int>> graphs(n_vertexes + 1);
    for (int i = 0; i < n_graphs; ++i) {
        int a, b;
        cin >> a >> b;
        graphs[b].emplace_back(a);
    }

    vector<int> reliability(n_vertexes + 1, 0);
    for (int i = 1; i < n_vertexes + 1; ++i) {
        reliability[i] = bfs(i, n_vertexes, graphs);
    }

    int max_reliability = *max_element(reliability.begin(), reliability.end());
    for (int i = 1; i < n_vertexes + 1; ++i) {
        if (reliability[i] == max_reliability) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}


int bfs(int start, int size, vector<vector<int>> &graphs) {
    int answer = 1;
    queue<int> q;
    q.emplace(start);
    vector<bool> visited(size + 1, false);
    visited[start] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graphs[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.emplace(next);
                answer++;
            }
        }
    }

    return answer;
}