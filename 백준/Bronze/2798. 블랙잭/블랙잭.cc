#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n = 0, target = 0, res = 0;
    cin >> n >> target;
    // 입력 2
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    // 비트 마스킹 (all bits are false except 3 bits)
    vector<int> bit(n, false);
    fill(bit.end() - 3, bit.end(), true);
    do {
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            // 비트가 true 이면 sum 에 더함 (한 루프에 true 인 비트는 3개임)
            if (bit[i])
                sum += cards[i];

            // 가지치기
            if (sum > target)
                break;
        }

        // target 과 값이 가까우면 res 에 저장
        if (sum <= target)
            res = max(res, sum);

    } while (next_permutation(bit.begin(), bit.end()));

    cout << res << endl;
    return 0;
}
