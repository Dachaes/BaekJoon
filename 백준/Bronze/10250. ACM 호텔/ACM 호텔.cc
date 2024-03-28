#include <iostream>
using namespace std;

int main() {
    int testNo = 0;
    cin >> testNo;

    for (int i = 0; i < testNo; i++) {
        int height = 0, width = 0, questNo = 0;
        int roomNo = 0, roomNo1 = 0, roomNo2 = 0;

        cin >> height >> width >> questNo;

        roomNo1 = (questNo % height == 0) ? height : questNo % height;
        roomNo2 = (questNo - 1) / height + 1;
        roomNo = roomNo1 * 100 + roomNo2;

        cout << roomNo << '\n';
    }

    return 0;
}