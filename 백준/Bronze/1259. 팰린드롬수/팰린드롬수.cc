#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string str_num, rev_num;
    cin >> rev_num;

    while (rev_num != "0") {
        str_num = rev_num;
        reverse(rev_num.begin(), rev_num.end());

        if (str_num == rev_num)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        cin >> rev_num;
    }

    return 0;

}