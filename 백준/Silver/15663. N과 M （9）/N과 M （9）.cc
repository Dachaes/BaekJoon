#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM9(int, int, vector<int>&, vector<int>&, vector<bool>&);

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

    vector<int> nm9;
    vector<bool> used(n_numbers, false);
    NM9(n_numbers, n_seq, numbers, nm9,used);

    return 0;
}


void NM9(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm9, vector<bool>& used) {
    if (nm9.size() == n_seq) {
        for (int nm : nm9)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    int prev = 0;
    for (int i = 0; i < n_numbers; ++i) {
        int number = numbers[i];
        if (!used[i] and prev != number) {
            nm9.push_back(number);
            used[i] = true;
            NM9(n_numbers, n_seq, numbers, nm9, used);
            nm9.pop_back();
            prev = number;
            used[i] = false;
        }
    }
}
