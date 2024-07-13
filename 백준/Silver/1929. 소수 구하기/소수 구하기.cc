#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    set<int> numbers;
    vector<bool> checks(m + 1, false);
    for (int i = n; i <= m; ++i) {
        numbers.insert(i);
    }
    numbers.erase(1);

    // num: '에라토스테네스의 체' 알고리즘으로 체크할 숫자
    int num = 0;
    for (int i = 2; i <= m; ++i) {
        num = i;

        // 1. 이미 체크가 되었다면, 더 이상 체크하지 않아도 좋으므로 다음 숫자로 넘어감
        if (checks[num])
            continue;

        // 2. 체크가 되지 않았다면, num 의 배수를 모두 확인하며 지움
        checks[num] = true;

        for (int j = 2; ; ++j) {
            num = i * j;

            if (m < num)
                break;
            numbers.erase(num);
            checks[num] = true;
        }
    }

    for (int number : numbers) {
        cout << number << '\n';
    }

    return 0;
}
