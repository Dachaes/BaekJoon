#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct compare {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return (abs(a) > abs(b));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_numbers = 0;         cin >> n_numbers;
    priority_queue<int, vector<int>, compare> numbers;

    int number = 0;
    for (int i = 0; i < n_numbers; ++i) {
        cin >> number;

        if (number == 0) {
            if (numbers.empty()) {
                cout << '0' << '\n';
            }
            else {
                cout << numbers.top() << '\n';
                numbers.pop();
            }
        }
        else {
            numbers.emplace(number);
        }
    }
    
    return 0;
}