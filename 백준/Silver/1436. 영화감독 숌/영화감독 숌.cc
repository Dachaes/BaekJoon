#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 0;
    cin >> n;

    int num = 666, cnt = 0;
    string str_num;

    while (cnt != n) {
        str_num = to_string(num);
        num = stoi(str_num);
        if (str_num.find("666") != string::npos)
            cnt += 1;
        num++;
    }

    cout << str_num << endl;
    return 0;
}