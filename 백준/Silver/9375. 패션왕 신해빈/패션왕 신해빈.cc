#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1
    int n_tests = 0, n_clothes = 0;
    cin >> n_tests;

    // 테스트 케이스 계산
    for (int t = 0; t < n_tests; ++t) {
        cin >> n_clothes;
        // 입력 2
        unordered_map<string, int> clothes;
        for (int i = 0; i < n_clothes; ++i) {
            string clothe, clothe_type;
            cin >> clothe >> clothe_type;
            clothes[clothe_type]++;
        }

        int res = 1;
        for (auto clothe : clothes) {
            res *= (clothe.second + 1);
        }
        cout << res - 1 << '\n';
    }

    return 0;
}