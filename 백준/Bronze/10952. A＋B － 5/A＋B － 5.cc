#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;

    while (true) {
        cin >> a >> b;
        if (a != 0 and b != 0)
            cout << a + b << '\n';
        else
            break;
    }

    return 0;
}