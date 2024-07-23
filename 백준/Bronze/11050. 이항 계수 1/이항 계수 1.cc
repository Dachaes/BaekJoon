#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0, m = 0;
    cin >> n >> m;

    // 비트 마스킹으로 체크 (n 개 중 m 개를 선택 - 조합)
    vector<int> checks(n, false);
    fill(checks.end() - m, checks.end(), true);

    int count = 0;
    do {
        count++;
    } while (next_permutation(checks.begin(), checks.end()));

    cout << count << endl;
    return 0;
}