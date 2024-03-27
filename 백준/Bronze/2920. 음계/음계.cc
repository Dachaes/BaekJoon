#include <iostream>
using namespace std;

int main() {
    string melody;
    getline(cin, melody);

    string asc = "1 2 3 4 5 6 7 8";
    string des = "8 7 6 5 4 3 2 1";

    if (melody == asc) {
        cout << "ascending" << '\n';
    }
    else if (melody == des) {
        cout << "descending" << '\n';
    }
    else {
        cout << "mixed" << '\n';
    }

    return 0;
}