#include <iostream>
using namespace std;

int main() {
    int number = 0, max = 0, idx = 0;
    for (int i = 0; i < 9; i++){
        cin >> number;
        if (max < number){
            max = number;
            idx = i + 1;
        }
    }

    cout << max << '\n' << idx << '\n';
    return 0;
}