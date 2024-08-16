#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM8(int, int, vector<int>&, vector<int>&, int);

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

    vector<int> nm8;
    NM8(n_numbers, n_seq, numbers, nm8, 0);

    return 0;
}


void NM8(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm8, int used) {
    if (nm8.size() == n_seq) {
        for (int nm : nm8)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n_numbers; ++i) {
        int number = numbers[i];
        if (used <= number) {
            nm8.push_back(number);
            NM8(n_numbers, n_seq, numbers, nm8, number);
            nm8.pop_back();
        }
    }
}
