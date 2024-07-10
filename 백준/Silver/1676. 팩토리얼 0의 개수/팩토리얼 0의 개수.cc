#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 0;
    cin >> n;

    // numX: n!은 X로 몇 번 나누어 지는가?
    int num2 = 0, num5 = 0;

    // num: 계산할 값
    int num = n;
    while (n != 0) {
        num = n;
        while (num % 10 == 0) {
            num2 += 1;
            num5 += 1;
            num /= 10;
        }
        while (num % 2 == 0) {
            num2 += 1;
            num /= 2;
        }
        while (num % 5 == 0) {
            num5 += 1;
            num /= 5;
        }

        n--;
    }

    cout << min(num2, num5) << endl;
    return 0;
}