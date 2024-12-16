#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;
    
    stack<pair<long long, int>> s;
    s.emplace(a, 1);
    long long num, new_num;
    int dep;

    while(!s.empty()) {
        num = s.top().first;
        dep = s.top().second;
        s.pop();

        // 1
        new_num = num * 2;
        if (new_num <= b) {
            if (new_num == b) {
                cout << dep + 1 << endl;
                return 0;
            }
            s.emplace(new_num, dep + 1);
        }

        // 2
        new_num = num * 10 + 1;
        if (new_num <= b) {
            if (new_num == b) {
                cout << dep + 1 << endl;
                return 0;
            }
            s.emplace(new_num, dep + 1);
        }
    }
    
    cout << -1 << endl;

    return 0;
}