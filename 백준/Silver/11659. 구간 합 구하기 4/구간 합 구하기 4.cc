#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n_numbers = 0;          cin >> n_numbers;
    int n_calculations = 0;     cin >> n_calculations;

    // 입력 2
    vector<int> numbers(n_numbers);
    for (int i = 0; i < n_numbers; ++i) {
        cin >> numbers[i];

        if (i != 0)
            numbers[i] += numbers[i - 1];
    }

    // 입력 3 + 계산
    for (int i = 0; i < n_calculations; ++i) {
        int start = 0, end = 0;
        cin >> start >> end;
        start--;    end--;

        if (start == 0)
            cout << numbers[end] << '\n';
        else
            cout << numbers[end] - numbers[start - 1] << '\n';
    }

    return 0;
}