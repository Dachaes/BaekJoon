#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void Permutation(int, int, vector<int>&, vector<bool>&);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n_numbers = 0;    cin >> n_numbers;
    int n_perm = 0;       cin >> n_perm;

    // 순열
    vector<int> permutation;
    vector<bool> used(n_numbers + 1, false);

    Permutation(n_numbers, n_perm, permutation, used);

    return 0;
}


void Permutation(int n_numbers, int n_perm, vector<int>& permutation, vector<bool>& used) {
    // 한 세트의 순열 제작 완료
    if (permutation.size() == n_perm) {
        for (int number : permutation) {
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
        permutation.push_back(i);
        Permutation(n_numbers, n_perm, permutation, used);
        permutation.pop_back();
        used[i] = false;
    }
}
