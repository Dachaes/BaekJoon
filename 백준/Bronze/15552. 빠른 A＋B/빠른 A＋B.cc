#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_tests;
    cin >> n_tests;
    for (int i = 0; i < n_tests; ++i) {
        int n, m;
        cin >> n >> m;
        cout << n + m << '\n';
    }

    return 0;
}