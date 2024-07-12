#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 0, m = 0;
    // 입력 numbers
    cin >> n;
    unordered_set<int> numbers;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        numbers.insert(num);
    }
    // 입력 target, numbers 에 있는지 찾기
    cin >> m;
    int target = 0;
    for (int i = 0; i < m; ++i) {
        cin >> target;
        if (numbers.find(target) != numbers.end())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}
