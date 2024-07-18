#include <iostream>
using namespace std;


int GCD(int, int);
int LCM(int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;

    int gcd = num1 >= num2? GCD(num1, num2) : GCD(num2, num1);
    int lcm = LCM(num1, num2, gcd);
    cout << gcd << '\n' << lcm << '\n';

    return 0;
}


// Greatest Common Divisor (최대 공약수)
int GCD(int a, int b) {
    // 계산
    int r = 0;
    while (a != 0 and b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}


// Lowest Common Multiple (최소 공배수)
int LCM(int a, int b, int gcd) {
    return (a * b) / gcd;
}