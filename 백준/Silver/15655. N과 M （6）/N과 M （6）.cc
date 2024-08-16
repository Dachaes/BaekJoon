#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM6(int, int, vector<int>&, vector<int>&, int);

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

    vector<int> nm6;
    NM6(n_numbers, n_seq, numbers, nm6, 0);

    return 0;
}


void NM6(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm6, int used) {
    if (nm6.size() == n_seq) {
        for (int nm : nm6)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n_numbers; ++i) {
        int number = numbers[i];
        if (used < number) {
            nm6.push_back(number);
            NM6(n_numbers, n_seq, numbers, nm6, number);
            nm6.pop_back();
        }
    }
}
