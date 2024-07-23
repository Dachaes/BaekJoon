#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0, m = 0;
    cin >> n >> m;
    queue<int> numbers;

    for (int i = 0; i < n; ++i) {
        numbers.emplace(i + 1);
    }

    int count = 0;
    cout << '<';
    while (true) {
        int number = numbers.front();
        numbers.pop();
        count ++;

        if (count == m) {
            cout << number;

            // 비었는지 체크
            if (!numbers.empty()) {
                cout << ", ";
            }
            else
                break;
            count = 0;
        }
        else {
            numbers.emplace(number);
        }

    }
    cout << '>';

    return 0;
}