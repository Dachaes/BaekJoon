#include <iostream>
using namespace std;

int main() {
    int n = 0, x = 0;
    cin >> n >> x;

    int num = 0;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        if (num < x) {
            cout << num << ' ';
        }
    }

    return 0;
}