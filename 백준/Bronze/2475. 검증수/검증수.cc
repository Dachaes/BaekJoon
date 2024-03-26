#include <iostream>
using namespace std;

int main() {
    string nums;
    getline(cin, nums);

    int pow, sum = 0;
    for (char num : nums){
        if (num != ' ') {
            num = num - '0';
            pow = num * num;
            sum += pow;
        }
    }
    cout << sum % 10 << '\n';

    return 0;
}