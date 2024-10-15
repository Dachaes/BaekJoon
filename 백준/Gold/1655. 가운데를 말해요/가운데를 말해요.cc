#include <iostream>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;

    for (int i = 0; i < n; ++i) {
        int number;
        cin >> number;

        left.emplace(number);
        right.emplace(left.top());
        left.pop();

        if (left.size() < right.size()) {
            left.emplace(right.top());
            right.pop();
        }

        cout << left.top() << '\n';
    }

    return 0;
}