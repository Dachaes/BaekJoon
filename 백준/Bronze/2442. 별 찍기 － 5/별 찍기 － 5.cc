#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max = 2 * (n - 1) + 1;
    char star = '*';
    string padding;
    string stars;
    for (int i = 0; i < n; i++) {
        stars = string(2 * i + 1, star);
        padding = string((max - stars.size()) / 2, ' ');
        cout << padding << stars << '\n';
    }

    return 0;
}