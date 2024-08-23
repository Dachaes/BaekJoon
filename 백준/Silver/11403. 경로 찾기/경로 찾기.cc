#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


int bfs(int, int, int, vector<vector<int>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;          cin >> n;

    vector<vector<int>> maps(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int answer = bfs(i, j, n, maps);
            cout << answer << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}


int bfs(int start, int end, int n, vector<vector<int>>& arr) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.emplace(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next = 0; next < n; ++next) {
            if (!visited[next] and arr[now][next] == 1) {
                if (next == end)
                    return 1;

                q.emplace(next);
                visited[next] = true;
            }
        }
    }

    return 0;
}