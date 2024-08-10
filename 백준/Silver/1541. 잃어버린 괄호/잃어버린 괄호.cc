#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    string formula;     getline(cin, formula);
    string number;
    int result = 0;
    bool minus_flag = false;

    for (char f : formula) {
        if (f == '+') {
            result += minus_flag? -stoi(number) : stoi(number);
            number = "";
        }
        else if (f == '-') {
            result += minus_flag? -stoi(number) : stoi(number);

            minus_flag = true;
            number = "";
        }
        else {
            number += f;
        }
    }
    result += minus_flag? -stoi(number) : stoi(number);

    cout << result << '\n';
    return 0;
}