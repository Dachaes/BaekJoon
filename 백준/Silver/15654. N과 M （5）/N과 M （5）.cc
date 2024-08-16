#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM5(int, int, vector<int>&, vector<int>&, vector<bool>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n_numbers = 0;    cin >> n_numbers;
    int n_seq = 0;       cin >> n_seq;

    // 입력
    vector<int> numbers(n_numbers);
    for (int i = 0; i < n_numbers; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    vector<int> nm5;
    vector<bool> used(n_numbers + 1, false);
    NM5(n_numbers, n_seq, numbers, nm5, used);

    return 0;
}


void NM5(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm5, vector<bool>& used) {
    if (nm5.size() == n_seq) {
        for (int nm : nm5)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n_numbers; ++i) {
        if (!used[i]) {
            nm5.push_back(numbers[i]);
            used[i] = true;
            NM5(n_numbers, n_seq, numbers, nm5, used);
            nm5.pop_back();
            used[i] = false;
        }
    }
}
