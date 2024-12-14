#include <iostream>
#include <set>
#define endl '\n'
using namespace std;


set<string> answers;
void cal(int, int, string);
void cal2(string);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_tc;
    cin >> n_tc;

    while(n_tc--) {
        int n;
        cin >> n;

        cal(n, 2, "1");

        for (string answer : answers) {
            cout << answer << endl;
        }

        if (n_tc != 0) {
            cout << endl;
            answers.clear();
        }
    }

    return 0;
}


void cal(int size, int cnt, string str) {
    if (cnt > size) {
        cal2(str);
        return;
    }

    string new_str;

    // 덧셈
    new_str = str + "+" + to_string(cnt);
    cal(size, cnt + 1, new_str);

    // 뺄셈
    new_str = str + "-" + to_string(cnt);
    cal(size, cnt + 1, new_str);

    // 공백
    new_str = str + " " + to_string(cnt);
    cal(size, cnt + 1, new_str);
}


void cal2(const string str) {
    string num;
    int sum = 0;
    char last_operator = '+';

    for (char c : str) {
        if (isdigit(c)) {
            num += c;
        }
        else if (c == '+') {
            if (last_operator == '+')
                sum += stoi(num);
            else if (last_operator == '-')
                sum -= stoi(num);

            last_operator = '+';
            num = "";
        }
        else if (c == '-') {
            if (last_operator == '+')
                sum += stoi(num);
            else if (last_operator == '-')
                sum -= stoi(num);

            last_operator = '-';
            num = "";
        }
    }

    if (!num.empty()) {
        if (last_operator == '+')
            sum += stoi(num);
        else if (last_operator == '-')
            sum -= stoi(num);
    }

    if (sum == 0) {
        answers.emplace(str);
    }
}