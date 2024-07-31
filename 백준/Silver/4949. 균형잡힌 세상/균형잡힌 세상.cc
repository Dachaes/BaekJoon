#include <iostream>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string sentence;

    while (true) {
        getline(cin, sentence);
        // 종료 조건
        if (sentence == ".")
            break;

        // 문자열 괄호 계산
        stack<char> brackets;
        for (char s:sentence) {
            // 1. '(', '['
            if (s == '(' or s == '[') {
                brackets.emplace(s);
            }
            // 2. ')'
            else if (s == ')') {
                // 안되는 조건
                if (brackets.empty()) {
                    brackets.emplace(s);
                    break;
                }
                else {
                    char pre_bracket = brackets.top();
                    if (pre_bracket == '(') {
                        brackets.pop();
                    }
                    else
                        brackets.emplace(s);
                }
            }
            // 3. ']'
            else if (s == ']') {
                // 안되는 조건
                if (brackets.empty()) {
                    brackets.emplace(s);
                    break;
                }
                else {
                    char pre_bracket = brackets.top();
                    if (pre_bracket == '[') {
                        brackets.pop();
                    }
                    else
                        brackets.emplace(s);
                }
            }
        }

        if (brackets.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}