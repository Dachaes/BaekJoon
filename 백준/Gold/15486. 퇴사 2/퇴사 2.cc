#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;      cin >> n;
    vector<int> dp(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        // 입력
        int date_required, cost;     cin >> date_required >> cost;

        // 현재까지 얻은 최대 이익을 다음 날짜로 갱신
        dp[i] = max(dp[i], dp[i - 1]);

        // 상담이 끝나는 날짜가 퇴사일을 넘지 않는 경우에 체크
        if (i + date_required <= n + 1) {
            dp[i + date_required] = max(dp[i + date_required], dp[i] + cost);
        }
    }

    int answer = *max_element(dp.begin(), dp.end());
    cout << answer << endl;
    return 0;
}