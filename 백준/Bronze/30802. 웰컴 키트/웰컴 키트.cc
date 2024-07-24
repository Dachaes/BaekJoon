#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 1 - 총 인원 수
    int n = 0;
    cin >> n;

    // 입력 2 - 셔츠 사이즈
    vector<int> shirts(6);
    for (int i = 0; i < 6; ++i) {
        cin >> shirts[i];
    }

    // 입력 3 - 티셔츠 묶음, 펜 묶음
    int n_shirts = 0, n_pens = 0;
    cin >> n_shirts >> n_pens;

    // 셔츠를 몇 묶음 주문해야 하는지 계산
    int res_shirts = 0;
    for (int i = 0; i < 6; ++i) {
        if (shirts[i] % n_shirts == 0)
            res_shirts += shirts[i] / n_shirts;
        else
            res_shirts += shirts[i] / n_shirts + 1;
    }

    // 펜을 얼마나 주문해야 하는지 계산
    int res_pens1 = n / n_pens;
    int res_pens2 = n % n_pens;

    // 출력
    cout << res_shirts << '\n';
    cout << res_pens1 << ' ' << res_pens2 << '\n';
    return 0;
}