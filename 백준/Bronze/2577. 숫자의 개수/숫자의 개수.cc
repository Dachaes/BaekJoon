#include <iostream>
using namespace std;

int main() {
    int number = 0, res = 1;
    int count[10] = {};
    for (int i = 0; i < 3; i++){
        cin >> number;
        res *= number;
    }

    string strRes = to_string(res);
    for (char num : strRes) {
        count[num - '0'] += 1;
    }

    for (int c : count) {
        cout << c << '\n';
    }

    return 0;
}