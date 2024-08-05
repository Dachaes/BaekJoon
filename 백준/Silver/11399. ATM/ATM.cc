#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 0;
    cin >> n;
    multiset<int> times;
    for (int i = 0; i < n; ++i) {
        int time = 0;
        cin >> time;
        times.emplace(time);
    }

    int res = 0;
    for (int time : times) {
        res += time * n;
        n--;
    }

    cout << res << endl;
    return 0;
}
