#include <iostream>
using namespace std;

int main() {
    int hour = 0, min = 0;
    cin >> hour >> min;

    min -= 45;
    if (min < 0){
        hour -= 1;
        min = 60 + min;
    }
    if (hour == -1){
        hour = 23;
    }

    cout << hour << ' ' << min << '\n';

    return 0;
}