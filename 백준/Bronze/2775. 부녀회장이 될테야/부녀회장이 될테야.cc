#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 - 테스트 케이스
    int n_tests = 0;
    cin >> n_tests;

    vector<vector<int>> rooms(15, vector<int>(15, 0));
    // 0층 계산
    int max_floor = 0;
    for (int i = 0; i < 15; ++i) {
        rooms[0][i] = i;
    }

    // 테스트 케이스 별 계산
    for (int t = 0; t < n_tests; ++t) {
        // k층의 n번 방의 거주민 수 구하기
        int k = 0, n = 0;
        cin >> k >> n;

        // 가지치기 - 이미 인원이 체크 되었으면 continue!
        if (k <= max_floor) {
            cout << rooms[k][n] << '\n';
            continue;
        }

        // 인원 체크
        for (int floor = max_floor + 1; floor < k + 1; ++floor) {
            rooms[floor][1] = 1;
            for (int room_number = 2; room_number < 15; ++room_number) {
                rooms[floor][room_number] = rooms[floor][room_number - 1] + rooms[floor - 1][room_number];
            }
        }

        // 최종적으로 최대 계산된 층 수를 갱신
        max_floor = max(max_floor, k);

        cout << rooms[k][n] << '\n';
    }

    return 0;
}