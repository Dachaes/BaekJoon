#include <iostream>
#include <cmath>
using namespace std;


int answer = 0;
void devide(int tx, int ty, int x, int y, int size) {
    // 찾음
    if (tx == x and ty == y) {
        return;
    }

    // 찾는 위치가 제 1사분면일 경우
    if (tx < x + size / 2 and y + size / 2 <= ty) {
        devide(tx, ty, x, y + size / 2, size / 2);
        answer += (size / 2) * (size / 2);
    }
    // 찾는 위치가 제 2사분면일 경우
    else if (tx < x + size / 2 and ty < y + size / 2) {
        devide(tx, ty, x, y, size / 2);
    }
    // 찾는 위치가 제 3사분면일 경우
    else if (x + size / 2 <= tx and ty < y + size / 2 ) {
        devide(tx, ty, x + size / 2, y, size / 2);
        answer += (size / 2) * (size / 2) * 2;
    }
    // 찾는 위치가 제 4사분면일 경우
    else if (x + size / 2 <= tx and y + size / 2 <= ty) {
        devide(tx, ty, x + size / 2, y + size / 2, size / 2);
        answer += (size / 2) * (size / 2) * 3;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int n = 0;             cin >> n;
    int target_x = 0;      cin >> target_x;
    int target_y = 0;      cin >> target_y;

    devide(target_x, target_y, 0, 0, pow(2, n));

    cout << answer << '\n';
    return 0;
}