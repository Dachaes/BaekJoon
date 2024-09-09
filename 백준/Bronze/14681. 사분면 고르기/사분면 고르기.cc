#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x = 0, y = 0;
    cin >> x >> y;
    if (x > 0) {
        if (y > 0)
            cout << '1' << '\n';
        else
            cout << '4' << '\n';
    }
    else {
        if (y > 0)
            cout << '2' << '\n';
        else
            cout << '3' << '\n';
    }

    return 0;
}