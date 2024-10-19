#include <iostream>
#include <regex>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    regex re("^(100+1+|01)+$");

    int n_tests;        cin >> n_tests;
    for(int tc = 0; tc < n_tests; ++tc) {
        cin >> str;
        if (regex_match(str, re))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}