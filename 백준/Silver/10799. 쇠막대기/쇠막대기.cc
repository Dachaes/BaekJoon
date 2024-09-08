#include <iostream>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string lasers;       cin >> lasers;
    stack<char> s_laser;

    int answer = 0;
    for (int i = 0; i < lasers.length(); ++i) {
        char laser = lasers[i];
        if (laser == '(') {
            s_laser.emplace(laser);
        }
        else if (laser == ')') {
            s_laser.pop();
            char prev_laser = lasers[i - 1];
            // 레이저 o
            if (prev_laser == '(')
                answer += s_laser.size();
            // 레이저 x
            else if (prev_laser == ')')
                answer += 1;
        }
    }

    cout << answer << '\n';

    return 0;
}