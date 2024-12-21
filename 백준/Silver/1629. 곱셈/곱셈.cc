#include <iostream>
#include <vector>
#include <climits>
#define endl '\n'
using namespace std;


long long power(long long, long long, long long);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    long long a, b, c;
    cin >> a >> b >> c;

    cout << power(a, b, c) << endl;

    return 0;
}


long long power(long long a, long long b, long long c) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a % c;

    long long tmp1 = power(a, b/2, c);
    if (b % 2 == 0)
        return tmp1 * tmp1 % c;
    else
        return tmp1 * power(a, b/2 + 1, c) % c;
}