#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n_tests = 0;    cin >> n_tests;
    vector<long long> padovan_sequence({0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12});
    padovan_sequence.resize(101, -1);
    int max_number = 11;

    // 테스트 케이스 계산
    for (int t = 0; t < n_tests; ++t) {
        int number;     cin >> number;

        // 이미 구한 것
        if (padovan_sequence[number] != -1) {
            cout << padovan_sequence[number] << '\n';
            continue;
        }

        // 아직 구하지 않은 것
        for (int i = max_number + 1; i <= number; ++i) {
            padovan_sequence[i] = padovan_sequence[i - 1] + padovan_sequence[i - 5];
        }

        cout << padovan_sequence[number] << '\n';
        max_number = number;
    }

    return 0;
}