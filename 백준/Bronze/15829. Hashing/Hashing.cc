#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;

    // 입력 2
    string words;
    cin >> words;

    long long r = 1, m = 1234567891, sum = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        char word = words[i];
        sum = (sum + (word - 96) * r) % m;
        r = r * 31 % m;
    }
    res = sum;

    cout << res << endl;
    return 0;
}