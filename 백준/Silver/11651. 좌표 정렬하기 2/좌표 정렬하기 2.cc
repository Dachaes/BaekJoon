#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct compare {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        else
            return a.first > b.first;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;
    // 입력 2
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> points;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        points.emplace(x, y);
    }

    // 출력
    while(!points.empty()) {
        pair<int, int> point = points.top();
        points.pop();
        cout << point.first << ' ' << point.second << '\n';
    }
    return 0;
}