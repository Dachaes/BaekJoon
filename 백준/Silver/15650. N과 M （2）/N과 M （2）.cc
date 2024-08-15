#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n_numbers = 0;    cin >> n_numbers;
    int n_perm = 0;       cin >> n_perm;

    // 조합
    vector<bool> checks(n_numbers, false);
    fill(checks.begin(), checks.begin() + n_perm, true);

    do {
        for (int i = 0; i < n_numbers; ++i) {
            if (checks[i])
                cout << i + 1 << ' ';
        }
        cout << '\n';
    } while(prev_permutation(checks.begin(), checks.end()));

    return 0;
}