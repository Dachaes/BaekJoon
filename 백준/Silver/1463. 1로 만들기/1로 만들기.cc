#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;
    cin >> n;

    vector<int> numbers(n + 1);
    numbers[1] = 0;
    if (n >= 2)
        numbers[2] = 1;
    if (n >= 3)
        numbers[3] = 1;

    int a = 0, b = 0, c = 0;
    for (int i = 4; i < n + 1; ++i) {
        a = numbers[i - 1] + 1;

        if (i % 2 == 0) {
            b = numbers[i / 2] + 1;
            a = min(a, b);
        }
        if (i % 3 == 0) {
            c = numbers[i / 3] + 1;
            a = min(a, c);
        }

        numbers[i] = a;
    }

    cout << numbers[n] << endl;
    return 0;
}