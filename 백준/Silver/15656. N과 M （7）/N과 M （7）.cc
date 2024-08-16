#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM7(int, int, vector<int>&, vector<int>&);

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

    vector<int> nm7;
    NM7(n_numbers, n_seq, numbers, nm7);

    return 0;
}


void NM7(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm7) {
    if (nm7.size() == n_seq) {
        for (int nm : nm7)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n_numbers; ++i) {
        nm7.push_back(numbers[i]);
        NM7(n_numbers, n_seq, numbers, nm7);
        nm7.pop_back();
    }
}
