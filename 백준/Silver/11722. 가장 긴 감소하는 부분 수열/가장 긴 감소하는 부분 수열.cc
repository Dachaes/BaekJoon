#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;      cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        int number;     cin >> number;
        numbers[i] = number;
    }

    vector<int> dp(n, 1);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (numbers[j] > numbers[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int answer = *max_element(dp.begin(), dp.end());
    cout << answer << endl;
    return 0;
}