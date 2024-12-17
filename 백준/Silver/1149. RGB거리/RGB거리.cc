#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cost_r(n);
    vector<int> cost_g(n);
    vector<int> cost_b(n);
    vector<int> dp_r(n);
    vector<int> dp_g(n);
    vector<int> dp_b(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost_r[i] >> cost_g[i] >> cost_b[i];
    }
    
    dp_r[0] = cost_r[0];
    dp_g[0] = cost_g[0];
    dp_b[0] = cost_b[0];
    int cnt = 1;
    while(cnt < n) {
        dp_r[cnt] = min(dp_g[cnt - 1] + cost_r[cnt], dp_b[cnt - 1] + cost_r[cnt]);
        dp_g[cnt] = min(dp_r[cnt - 1] + cost_g[cnt], dp_b[cnt - 1] + cost_g[cnt]);
        dp_b[cnt] = min(dp_r[cnt - 1] + cost_b[cnt], dp_g[cnt - 1] + cost_b[cnt]);
        cnt++;
    }

    cout << min(min(dp_r[n - 1], dp_g[n - 1]), dp_b[n - 1]) << endl;

    return 0;
}