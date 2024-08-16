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

    // prev_num: 앞의 depth 에서 사용된 숫자
    // before_num: 현재의 depth 에서 이전에 사용된 숫자
    int prev_num = 0;
    int before_num = 0;
    if (!nm9.empty())
        prev_num = nm9.back();

    for (int i = 0; i < n_numbers; ++i) {
        int number = numbers[i];
        if (!used[i] and before_num != number and prev_num <= number) {
            nm9.push_back(number);
            used[i] = true;
            NM9(n_numbers, n_seq, numbers, nm9, used);
            nm9.pop_back();
            before_num = number;
            used[i] = false;
        }
    }
}
