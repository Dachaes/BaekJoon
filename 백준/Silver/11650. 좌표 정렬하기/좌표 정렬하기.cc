#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0, x = 0, y = 0;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> points;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        points.emplace(x, y);
    }

    while (!points.empty()) {
        pair<int, int> point = points.top();
        cout << point.first << ' ' << point.second << '\n';
        points.pop();
    }

    return 0;
}