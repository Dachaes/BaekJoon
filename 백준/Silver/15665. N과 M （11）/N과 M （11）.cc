#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM10(int, int, vector<int>&, vector<int>&);

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
    NM10(n_numbers, n_seq, numbers, nm9);

    return 0;
}


void NM10(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm10) {
    if (nm10.size() == n_seq) {
        for (int nm : nm10)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    // before_num: 현재의 depth 에서 이전에 사용된 숫자
    int before_num = 0;

    for (int i = 0; i < n_numbers; ++i) {
        int number = numbers[i];
        if (before_num != number) {
            nm10.push_back(number);
            NM10(n_numbers, n_seq, numbers, nm10);
            nm10.pop_back();
            before_num = number;
        }
    }
}
