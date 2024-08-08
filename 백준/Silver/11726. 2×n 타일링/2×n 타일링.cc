#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;          cin >> n;

    // DP
    vector<int> numbers({0, 1, 2});
    numbers.resize(n + 1);
    for (int i = 3; i <= n; ++i) {
        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10007;
    }

    cout << numbers[n] << '\n';
    return 0;
}