#include <iostream>
#include <vector>
using namespace std;


int pack_sugar(vector<int>&, int);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n = 0;
    cin >> n;

    vector<int> sugar(5001, 0);
    sugar[0] = sugar[1] = sugar[2] = sugar[4] = -1;
    sugar[3] = sugar[5] = 1;

    int answer =  pack_sugar(sugar, n);
    cout << answer << endl;

    return 0;
}


int pack_sugar(vector<int>& sugar, int target) {
    // 가지치기 - 이미 구해져 있는 값이면 그냥 인덱스로 찾아서 반환
    if (sugar[target] != 0) {
        return sugar[target];
    }

    // 설탕 (x)Kg = (x - 3)Kg + 한 묶음(3Kg) or (x - 5)Kg + 한 묶음(5Kg)
    int target_3 = pack_sugar(sugar, target - 3);
    int target_5 = pack_sugar(sugar, target - 5);

    if (target_3 == -1 and target_5 == -1)
        sugar[target] = -1;
    else if (target_3 == -1)
        sugar[target] = pack_sugar(sugar, target - 5) + 1;
    else if (target_5 == -1)
        sugar[target] = pack_sugar(sugar, target - 3) + 1;
    else
        sugar[target] = min(pack_sugar(sugar, target - 3) + 1, pack_sugar(sugar, target - 5) + 1);

    return sugar[target];
}