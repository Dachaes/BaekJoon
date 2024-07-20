#include <iostream>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 입력
    int n_tests = 0;
    cin >> n_tests;

    // 테스트 케이스 별 계산
    for (int i = 0; i < n_tests; ++i) {
        string brackets;
        cin >> brackets;

        stack<char> brackets_stack;
        char pre_bracket;
        // 1. 괄호를 앞에서부터 하나씩 꺼내어 체크
        bool isValid = true;
        for (char bracket : brackets) {
            // 2-1. 괄호가 '('일 경우
            if (bracket == '(')
                brackets_stack.emplace(bracket);

            // 2-2. 괄호가 ')' 일 경우
            else {
                // 짝이 없는 괄호이므로 불가능한 괄호 문자열
                if (brackets_stack.empty()) {
                    isValid = false;
                    break;
                }
                // 짝이 있으면, '(' 인지 ')' 인지 확인
                else {
                    pre_bracket = brackets_stack.top();
                    // '(' 면 지금 괄호인 ')' 과 짝이 맞음 -> pop!
                    if (pre_bracket == '(') {
                        brackets_stack.pop();
                    }
                    // ')' 면 지금 괄호인 '(' 과 짝이 안맞음 -> push!
                    else {
                        brackets_stack.emplace(bracket);
                    }
                }
            }
        }

        // 남은 괄호가 있으면 불가능한 괄호 문자열
        if (!brackets_stack.empty())
            isValid = false;

        if (isValid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}