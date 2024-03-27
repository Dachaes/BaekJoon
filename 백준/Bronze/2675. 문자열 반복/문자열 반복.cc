#include <iostream>
using namespace std;

int main() {
    int testNo = 0;
    cin >> testNo;

    for (int i = 0; i < testNo; i++){
        int cnt = 0;
        string str, res;

        cin >> cnt >> str;

        for (char s : str){
            string tmp = string(cnt, s);
            res += tmp;
        }
        cout << res << '\n';
    }

    return 0;
}