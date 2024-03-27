#include <iostream>
using namespace std;

int main() {
    int year = 0;
    cin >> year;

    if (year % 4 == 0){
        if (year % 100 != 0 or year % 400 == 0){
            cout << "1" << '\n';
        }
        else
            cout << "0" << '\n';
    }
    else
        cout << "0" << '\n';

    return 0;
}