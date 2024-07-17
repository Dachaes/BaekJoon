#include <iostream>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;
    cin >> n;

    set<int> numbers;
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        cin >> temp;
        numbers.insert(temp);
    }

    for (int number : numbers) {
        cout << number << '\n';
    }

    return 0;
}
