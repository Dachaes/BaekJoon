#include <iostream>
#include <vector>
using namespace std;


void NM1(int, int, vector<int>&, vector<bool>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n_numbers = 0;    cin >> n_numbers;
    int n_seq = 0;       cin >> n_seq;

    // 순열
    vector<int> nm1;
    vector<bool> used(n_numbers + 1, false);

    NM1(n_numbers, n_seq, nm1, used);

    return 0;
}


void NM1(int n_numbers, int n_seq, vector<int>& nm1, vector<bool>& used) {
    // 한 세트의 순열 제작 완료
    if (nm1.size() == n_seq) {
        for (int number : nm1) {
            cout << number << ' ';
        }
        cout << '\n';
        return;
    }

    // 순열 만드는 중...
    for (int i = 1; i <= n_numbers; ++i) {
        if (used[i])
            continue;

        used[i] = true;
        nm1.push_back(i);
        NM1(n_numbers, n_seq, nm1, used);
        nm1.pop_back();
        used[i] = false;
    }
}
