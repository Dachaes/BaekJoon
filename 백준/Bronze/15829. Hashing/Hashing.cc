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
    cin.ignore();
    getline(cin, words);

    long long sum = 0, res = 1;
    for (int i = 0; i < n; ++i) {
        char word = words[i];
        long long r = pow(31, i);
        sum += (word - 96) * r;
    }
    res = sum % 123456891;

    cout << res << endl;
    return 0;
}