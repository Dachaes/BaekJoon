#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_numbers = 0;         cin >> n_numbers;
    priority_queue<int, vector<int>, less<>> numbers;

    int number = 0;
    for (int i = 0; i < n_numbers; ++i) {
        cin >> number;

        if (number == 0) {
            if (numbers.empty()) {
                cout << '0' << '\n';
            }
            else {
                number = numbers.top();
                numbers.pop();
                cout << number << '\n';
            }
        }
        else {
            numbers.emplace(number);
        }
    }

    return 0;
}