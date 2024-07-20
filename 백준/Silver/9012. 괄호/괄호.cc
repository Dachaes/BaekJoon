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

        // 1. 괄호를 stack 에 정리
        stack<char> brackets_stack1, brackets_stack2;
        for (char bracket : brackets) {
            brackets_stack1.emplace(bracket);
        }

        // 2. 괄호를 뒤에서부터 하나씩 꺼내어 체크
        char pre_bracket, bracket;

        while (!brackets_stack1.empty()) {
            bracket = brackets_stack1.top();
            brackets_stack1.pop();

            // 2-1. 괄호가 ')'일 경우
            if (bracket == ')')
                brackets_stack2.emplace(bracket);

            // 2-2. 괄호가 '(' 일 경우
            else if (bracket == '('){
                // 끝이 열린 괄호므로 불가능한 문자열
                if (brackets_stack2.empty()) {
                    brackets_stack2.emplace(bracket);
                    break;
                }
                else {
                    pre_bracket = brackets_stack2.top();
                    if (pre_bracket == ')') {
                        brackets_stack2.pop();
                        pre_bracket = ' ';
                    }
                    else if (pre_bracket == '(') {
                        brackets_stack2.emplace(bracket);
                    }
                }
            }
        }

        if (brackets_stack2.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
