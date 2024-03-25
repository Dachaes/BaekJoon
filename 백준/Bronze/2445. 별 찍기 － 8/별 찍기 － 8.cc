#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max = 2 * n;
    char star = '*';
    string padding;
    string stars;
    for (int i = 1; i < n + 1; i++) {
        stars = string(i, star);
        padding = string((max - 2 * stars.size()), ' ');
        cout << stars << padding << stars << '\n';
    }
    for (int i = n - 1; i > 0; i--) {
        stars = string(i, star);
        padding = string((max - 2 * stars.size()), ' ');
        cout << stars << padding << stars << '\n';
    }

    return 0;
}