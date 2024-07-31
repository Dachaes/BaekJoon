#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string number;
    int num = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> number;
        if (number != "Fizz" and number != "Buzz" and number != "FizzBuzz") {
            if (i == 0)
                num = stoi(number) + 3;
            else if (i == 1)
                num = stoi(number) + 2;
            else
                num = stoi(number) + 1;

            if (num % 3 == 0 and num % 5 == 0)
                cout << "FizzBuzz" << endl;
            else if (num % 3 == 0)
                cout << "Fizz" << endl;
            else if (num % 5 == 0)
                cout << "Buzz" << endl;
            else
                cout << num << endl;

            break;
        }
    }

    return 0;
}