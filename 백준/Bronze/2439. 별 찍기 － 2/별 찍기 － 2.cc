#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        char star = '*';
        string stars = string(i, star);
        cout << setw(n) << stars << '\n';
    }

    return 0;
}