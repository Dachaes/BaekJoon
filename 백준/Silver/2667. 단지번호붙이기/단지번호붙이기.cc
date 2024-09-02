#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int bfs(pair<int, int>, int, vector<vector<int>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;     cin >> n;
    cin.ignore();
    vector<vector<int>> houses(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            houses[i][j] = c - '0';
        }
    }

    multiset<int> counts;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (houses[i][j] == 1) {
                int count = bfs({i, j}, n, houses);
                counts.emplace(count);
            }
        }
    }

    cout << counts.size() << '\n';
    for (int count : counts) {
        cout << count << "\n";
    }

    return 0;
}


int bfs(pair<int, int> start, int size, vector<vector<int>>& arr) {
    arr[start.first][start.second] = 0;
    queue<pair<int, int>> q;
    q.emplace(start.first, start.second);
    int counts = 1;

    while (!q.empty()) {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for (int p = 0; p < 4; ++p) {
            int next_x = curr_x + dx[p];
            int next_y = curr_y + dy[p];

            if (0 <= next_x and next_x < size and 0 <= next_y and next_y < size) {
                if (arr[next_x][next_y] == 1) {
                    arr[next_x][next_y] = 0;
                    q.emplace(next_x, next_y);
                    counts++;
                }
            }
        }
    }

    return counts;
}