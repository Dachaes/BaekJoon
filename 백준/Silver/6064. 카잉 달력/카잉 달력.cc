#include <iostream>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc = 0;     cin >> tc;
    while (tc--) {
        int m, n, goal_x, goal_y;
        cin >> m >> n >> goal_x >> goal_y;

        int x = 0, y = 0;
        int answer = 0;

        while (true) {
            // 1. y 가 goal_y 일 때
            x += goal_y;
            y = goal_y;
            answer += goal_y;

            x %= m;
            if (x == 0)
                x = m;

            // 탈출 조건 1: 정답
            if (x == goal_x) {
                cout << answer << endl;
                break;
            }


            // 2. y 가 n 일 때
            x += (n - goal_y);
            y = n;
            answer += (n - goal_y);

            x %= m;
            if (x == 0)
                x = m;

            // 탈출 조건 1: 정답
            if (y == goal_y && x == goal_x) {
                cout << answer << endl;
                break;
            }
            // 탈출 조건 2: 마지막 해
            if (x == m) {
                cout << -1 << endl;
                break;
            }
        }
    }

    return 0;
}