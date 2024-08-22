#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int flatten_map(int, int, vector<vector<int>>&, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;          cin >> n;
    int m = 0;          cin >> m;
    int remains = 0;    cin >> remains;

    vector<vector<int>> maps(n, vector<int>(m));
    int min_blocks = INT_MAX, max_blocks = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int blocks;
            cin >> blocks;
            maps[i][j] = blocks;

            min_blocks = min(min_blocks, blocks);
            max_blocks = max(max_blocks, blocks);
        }
    }

    int answer[2] = {INT_MAX, -1};
    for (int target = min_blocks; target <= max_blocks; ++target) {
        int time = flatten_map(n, m, maps, target, remains);

        if (time != -1 and answer[0] >= time) {
            answer[0] = time;
            answer[1] = target;
        }
    }

    cout << answer[0] << ' ' << answer[1] << '\n';
    return 0;
}


int flatten_map(int x, int y, vector<vector<int>>& arr, int target, int remains) {
    int time = 0;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            int diff = arr[i][j] - target;
            // 블럭 제거
            if (target < arr[i][j]) {
                remains += diff;
                time += (2 * diff);
            }
            // 블럭 추가
            else if (arr[i][j] < target) {
                remains += diff;
                time -= diff;
            }
        }
    }

    return (remains >= 0) ? time : -1;
}