#include <iostream>
using namespace std;

int main() {
    int points = 0;
    cin >> points;

    if (points >= 90)   cout << 'A' << '\n';
    else if (points >= 80)   cout << 'B' << '\n';
    else if (points >= 70)   cout << 'C' << '\n';
    else if (points >= 60)   cout << 'D' << '\n';
    else   cout << 'F' << '\n';

    return 0;
}