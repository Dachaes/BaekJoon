#include <iostream>
#include <vector>
using namespace std;


void NM3(int, int, vector<int>&, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n_numbers = 0;    cin >> n_numbers;
    int n_seq = 0;       cin >> n_seq;

    vector<int> nm3;
    NM3(n_numbers, n_seq, nm3, 0);
    return 0;
}


void NM3(int n_numbers, int n_seq, vector<int>& nm3, int prev) {
    if (nm3.size() == n_seq) {
        for (int nm : nm3)
            cout << nm << ' ';
        cout << '\n';

        return;
    }

    for (int i = 1; i <= n_numbers; ++i) {
        if (prev <= i) {
            nm3.push_back(i);
            NM3(n_numbers, n_seq, nm3, i);
            nm3.pop_back();
        }
    }
}
