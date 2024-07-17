#include <iostream>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int num = 0;
    cin >> num;
    string num_str = to_string(num);

    // 가장 작은 생성자 구하기 (num_ctor 를 증가시켜 확인)
    int num_ctor = 1;
    while (num_ctor < num) {
        // 분해합
        int sum = num_ctor;
        string num_ctor_str = to_string(num_ctor);

        for (char n_ctor_str : num_ctor_str) {
            sum += n_ctor_str - '0';
        }

        // 루프 탈출 조건
        if (sum == num){
            cout << num_ctor << endl;
            return 0;
        }
        else
            num_ctor++;
    }

    cout << 0 << endl;
    return 0;
}
