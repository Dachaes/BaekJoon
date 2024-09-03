#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_tests;        cin >> n_tests;
    for (int test = 0; test < n_tests; ++test) {
        multiset<int> ms;
        int n;          cin >> n;

        char command;
        int num;
        for (int i = 0; i < n; ++i) {
            cin >> command >> num;
            if (command == 'I') {
                ms.emplace(num);
            }
            else if (command == 'D') {
                if (ms.empty())
                    continue;

                if (num == 1)
                    ms.erase(prev(ms.end()));
                else if (num == -1)
                    ms.erase(ms.begin());
            }
        }

        if (ms.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }

    return 0;
}