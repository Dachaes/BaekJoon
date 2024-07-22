#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;
    cin >> n;

    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<>> members;
    for (int i = 0; i < n; ++i) {
        int age = 0;
        string name;

        cin >> age >> name;
        members.emplace(age, i, name);
    }

    // 출력
    tuple<int, int, string> member;
    while (!members.empty()) {
        member = members.top();
        cout << get<0>(member) << ' ' << get<2>(member) << '\n';
        members.pop();
    }

    return 0;
}