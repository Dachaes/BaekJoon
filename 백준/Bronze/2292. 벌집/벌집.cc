#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력 - 방 번호
    int target_room = 0;
    cin >> target_room;

    // 1, 7, 19, 37, 61
    int max_room = 1, floor = -1;
    for (int i = 0; ; ++i) {
        max_room += 6 * i;
        
        // 찾는 방이 최대 방 번호 안 쪽에 있다면 찾은 것!
        if (target_room <= max_room) {
            floor = i + 1;
            break;
        }
    }

    cout << floor << endl;
    return 0;
}