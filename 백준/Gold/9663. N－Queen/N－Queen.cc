#include <iostream>
#include <vector>
using namespace std;


int result = 0;
void n_queen(int, int, vector<int>&);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;    cin >> n;
    vector<int> check_list(n, -1);
    n_queen(0, n, check_list);

    cout << result << '\n';
    return 0;
}


void n_queen(int depth, int size, vector<int>& check) {
    if (depth == size) {
        result++;
        return;
    }

    // [depth][i] 칸 확인
    for (int i = 0; i < size; ++i) {
        bool flag = true;

        // 같은 행과 대각선 확인
        for (int pre_depth = 0; pre_depth < depth; ++pre_depth) {
            // 같은 행에 이미 퀸이 있나?
            if (check[pre_depth] == i) {
                flag = false;
                break;
            }
            // 대각선에 이미 퀸이 있나?
            if (check[pre_depth] != -1 and abs(depth - pre_depth) == abs(i - check[pre_depth])) {
                flag = false;
                break;
            }
        }

        if (flag) {
            check[depth] = i;
            n_queen(depth + 1, size, check);
            check[depth] = -1;
        }
    }
}
