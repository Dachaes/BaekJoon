#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second)
            return true;
        else if (a.second == b.second) {
            return a.first > b.first;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n_meetings = 0;      cin >> n_meetings;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> meetings;
    for (int i = 0; i < n_meetings; ++i) {
        int start, end;
        cin >> start >> end;
        meetings.emplace(start, end);
    }

    int time = 0;
    int answer = 0;
    while (!meetings.empty()) {
        int start = meetings.top().first;
        int end = meetings.top().second;
        if (time <= start) {
            answer++;
            time = end;
        }

        meetings.pop();
    }

    cout << answer << '\n';
    return 0;
}