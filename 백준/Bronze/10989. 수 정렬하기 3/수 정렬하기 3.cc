#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0;
    cin >> n;

    // 입력 2
    map<int, int> numbers;
    for (int i = 0; i < n; ++i) {
        int number = 0;
        cin >> number;
        numbers[number]++;
    }

    for (auto number:numbers) {
        for (int i = 0; i < number.second; ++i)
            cout << number.first << '\n';
    }
    return 0;
}