#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    cout << setprecision(20) << a / b << endl;

    return 0;
}