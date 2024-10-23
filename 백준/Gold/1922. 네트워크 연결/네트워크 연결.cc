#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#define endl '\n'
using namespace std;


int find_parent(vector<int> &, int);
void unite(vector<int> &, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    int n_vertexes, n_edges;
    cin >> n_vertexes >> n_edges;
    for (int i = 0; i < n_edges; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.emplace(make_pair(c, make_pair(a, b)));
    }

    vector<int> parent(n_vertexes + 1);
    iota(parent.begin(), parent.end(), 0);
    int answer = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int p1 = pq.top().second.first;
        int p2 = pq.top().second.second;
        pq.pop();

        if (find_parent(parent, p1) != find_parent(parent, p2)) {
            unite(parent, p1, p2);
            answer += cost;
        }
    }

    cout << answer << endl;

    return 0;
}


int find_parent(vector<int> &parent, int x) {
    if (parent[x] == x)
        return x;

    return find_parent(parent, parent[x]);
}

void unite(vector<int> &parent, int x, int y) {
    x = find_parent(parent, x);
    y = find_parent(parent, y);

    if (x < y) {
        parent[y] = x;
    }
    else
        parent[x] = y;
}