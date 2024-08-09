#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


void bfs(int, vector<vector<bool>>&);
void dfs(int, vector<vector<bool>>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 (정점의 개수, 간선의 개수, 시작 정점 번호)
    int num_vertexes = 0;       cin >> num_vertexes;
    int num_edges = 0;          cin >> num_edges;
    int start = 0;              cin >> start;

    // 입력 (간선)
    vector<vector<bool>> vertexes(num_vertexes + 1, vector<bool>(num_vertexes + 1, false));
    for (int i = 0; i < num_edges; ++i) {
        int point1 = 0, point2 = 0;
        cin >> point1 >> point2;
        vertexes[point1][point2] = true;
        vertexes[point2][point1] = true;
    }

    dfs(start, vertexes);
    cout << '\n';
    bfs(start, vertexes);
    cout << '\n';

    return 0;
}


void bfs(int start, vector<vector<bool>>& vertexes) {
    int num_vertexes = vertexes.size() - 1;
    vector<bool> checks(num_vertexes + 1, false);

    queue<int> q;
    q.emplace(start);
    checks[start] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';

        for (int i = 1; i <= num_vertexes; ++i) {
            if (vertexes[now][i] and !checks[i]) {
                q.emplace(i);
                checks[i] = true;
            }
        }
    }
}


void dfs(int start, vector<vector<bool>>& vertexes) {
    int num_vertexes = vertexes.size() - 1;
    vector<bool> checks(num_vertexes + 1, false);

    stack<int> s;
    s.emplace(start);
    checks[start] = true;
    cout << start << ' ';

    while(!s.empty()) {
        int now = s.top();
        checks[now] = true;


        bool check_flag = false;
        for (int i = 1; i <= num_vertexes; ++i) {
            if (vertexes[now][i] and !checks[i]) {
                s.emplace(i);
                checks[i] = true;
                cout << i << ' ';

                check_flag = true;
                break;
            }
        }

        if (!check_flag)
            s.pop();
    }
}
