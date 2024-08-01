#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;
    // 입력 2, 계산
    stack<int> numbers;
    int number = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> number;
        if (number == 0) {
            number = numbers.top();
            numbers.pop();
            res -= number;
        }
        else {
            numbers.emplace(number);
            res += number;
        }

    }

    cout << res << endl;
    return 0;
}