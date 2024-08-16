#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void NM12(int, int, vector<int>&, vector<int>&);

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

    vector<int> nm12;
    NM12(n_numbers, n_seq, numbers, nm12);

    return 0;
}


void NM12(int n_numbers, int n_seq, vector<int>& numbers, vector<int>& nm12) {
    if (nm12.size() == n_seq) {
        for (int nm : nm12)
            cout << nm << ' ';
        cout << '\n';
        return;
    }

    // prev_num: 앞의 depth 에서 사용된 숫자
    // before_num: 현재의 depth 에서 이전에 사용된 숫자
    int prev_num = 0;
    int before_num = 0;
    if (!nm12.empty())
        prev_num = nm12.back();

    for (int i = 0; i < n_numbers; ++i) {
        int number = numbers[i];
        if (before_num != number and prev_num <= number) {
            nm12.push_back(number);
            NM12(n_numbers, n_seq, numbers, nm12);
            nm12.pop_back();
            before_num = number;
        }
    }
}
