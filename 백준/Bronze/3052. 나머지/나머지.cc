#include <iostream>
using namespace std;

int main() {
    int count[42] = {};
    int number = 0, result = 0;

    for (int i = 0; i < 10; i++) {
        cin >> number;
        count[number % 42] += 1;

        if (count[number % 42] == 1) {
            result += 1;
        }
    }

    cout << result << '\n';

    return 0;
}