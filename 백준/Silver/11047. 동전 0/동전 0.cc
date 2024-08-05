#include <iostream>
#include <vector>
using namespace std;


int binary_search(vector<int>, int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 (동전은 n가지의 종류, 가치의 합을 k로 만드려 함)
    int n_coins = 0, target = 0;
    cin >> n_coins >> target;

    // 입력 (동전의 가치들)
    vector<int> coins(n_coins);
    for (int i = 0; i < n_coins; ++i) {
        cin >> coins[i];
    }

    // 분할정복 (target 과 가까운 동전의 가치 찾기) + 그리디
    int max_index = n_coins - 1, max_coin = 0, num_max_coin = 0, res = 0;
    while (target != 0) {
        max_index = binary_search(coins, 0, max_index, target);
        max_coin = coins[max_index];
        num_max_coin = target / max_coin;

        target -= max_coin * num_max_coin;
        res += num_max_coin;
    }

    cout << res << endl;
    return 0;
}


int binary_search(vector<int> numbers, int start, int end, int target) {
    int mid = 0, res = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        if (target == numbers[mid]) {
            res = mid;
            break;
        }
        else if (target < numbers[mid]) {
            end = mid - 1;
        }
        else {
            res = mid;
            start = mid + 1;
        }
    }

    return res;
}